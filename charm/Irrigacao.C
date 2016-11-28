#include "Irrigacao.decl.h"
#include "Irrigacao.h"
#include "main.decl.h"
#include <math.h>

extern /* readonly */ CProxy_Main mainProxy;
extern /* readonly */ int numChares;


Irrigacao::Irrigacao () { }
Irrigacao::Irrigacao (CkMigrateMessage *msg) { }


//void Irrigacao::worker (int emissor, double evap1, double evap2, int pos_ini, int pos_fim, int tamanho)
void Irrigacao::worker (int emissor, double evap1, double evap2)
{
//    Inicializa?o das variaveis

    Menor =100000000;
    ero = 0;
    Tsup = 0;
    SQE10 = 0;
    SQE20 = 0;
    SQE30 = 0;
    S1 = 0;
    S2 = 0;
    S3 = 0;
    Med = 0;
    SQT = 0;
    SQT1 = 0;
    SQT2 = 0;
    SQT3 = 0;
    R2 = 0;
    q = 0;
    qq = 0;
    qot = 0;
    q1 = 0;
    q2 = 0;
    q3 = 0;
    r = 0;
    KE = 0;
    KW = 0;
    KP = 0;
    KN = 0;
    KS = 0;
    AE = 0;
    AW = 0;
    AN = 0;
    AS = 0;
    APO = 0;
    PME = 0;
    PMW = 0;
    PMP = 0;
    PMN = 0;
    PMS = 0;
//////////////////////////////////////////

    dq=(qM-qo)/numChares;


	//CkPrintf("\"Executado no  chare %d no PE %d (pedido pelo chare %d)  (evap1=%f - evap2=%f ) %f \n", thisIndex, CkMyPe(), emissor,evap1,evap2,CkWallTimer());

    for (int j0=1; j0<=M; j0++)
    {
        for (int i=1; i<=L; i++)
        {
            T[i][j0]=T00;  //condio inicial para toda a malha
        }
    }

//---t = 0 h -------
    To[1][2]=T00;
    To[1][5]=T00;
    To[1][8]=T00;
    To[3][2]=T00;
    To[3][5]=T00;
    To[3][8]=T00;
    To[6][2]=T00;
    To[6][5]=T00;
    To[6][8]=T00;
    To[11][2]=T00;
    To[11][5]=T00;
    To[11][8]=T00;
//---t = 10 h -------
    T1[1][2]=0.75*T00;
    T1[1][5]=0.75*T00;
    T1[1][8]=0.75*T00;
    T1[3][2]=0.78*T00;
    T1[3][5]=0.8*T00;
    T1[3][8]=0.8*T00;
    T1[6][2]=0.7*T00;
    T1[6][5]=0.8*T00;
    T1[6][8]=0.9*T00;
    T1[11][2]=0.98*T00;
    T1[11][5]=0.85*T00;
    T1[11][8]=0.95*T00;
//---t = 20 h -------
    T2[1][2]=0.5*T00;
    T2[1][5]=0.5*T00;
    T2[1][8]=0.5*T00;
    T2[3][2]=0.65*T00;
    T2[3][5]=0.7*T00;
    T2[3][8]=0.75*T00;
    T2[6][2]=0.45*T00;
    T2[6][5]=0.7*T00;
    T2[6][8]=0.8*T00;
    T2[11][2]=0.97*T00;
    T2[11][5]=0.8*T00;
    T2[11][8]=0.95*T00;
//---t = 30 h -------
    T3[1][2]=0.3*T00;
    T3[1][5]=0.3*T00;
    T3[1][8]=0.35*T00;
    T3[3][2]=0.7*T00;
    T3[3][5]=0.6*T00;
    T3[3][8]=0.75*T00;
    T3[6][2]=0.6*T00;
    T3[6][5]=0.6*T00;
    T3[6][8]=0.75*T00;
    T3[11][2]=0.96*T00;
    T3[11][5]=0.75*T00;
    T3[11][8]=0.9*T00;

// aqui acontece a evaporacao no seguencial

//------------PROBLEMA INVERSO E DIRETO---------------------



   // for (int ii=pos_ini; ii <= pos_fim; ii++)   // contador dos chutes do PI
   // {
    if(thisIndex==0){
      ii =ii*1;
      }else{
        ii=ii*thisIndex;
        }

        q=qo+(ii-1)*dq;

        for (int j1=1; j1<=M; j1++)
        {
            for (int i=1; i<=L; i++)
            {
                T[i][j1]=T00;  //condio inicial para toda a malha
            }
        }
        for (int j2=1; j2<=L; j2++)
        {
            for (int i=1; i<=M; i++)
            {
                Sf[i][j2]=0;  //fonte zero para toda a malha
            }
        }

        for (int kk=1; kk<=nn; kk++)    //TEMPORAL
        {
            te[kk][1]=(kk-1)*dt;
            qq=q*exp(-0.05*((te[kk][1]-12)*(te[kk][1]-12)));
            for (int i=2; i<=(L-1); i++)
            {
                Tsup=evap1*te[kk][1]+evap2; //teta em z=0 pela evaporao
                for (int i1=1; i1<=L; i1++)
                {
                    T[1][i1]=Tsup; //condio de fronteira em z=0
                }
                for (int j=2; j<=(M-1); j++)
                {
//------------FONTE = TRANSPIRAO ----------------
                    q1=qq;
                    q2=qq;
                    q3=qq;
                    Sf[2][2]= qq*(T[2][2]-Tr);
                    Sf[3][2]= qq*(T[3][2]-Tr);
                    Sf[4][2]= qq*(T[4][2]-Tr);
                    Sf[4][3]=q1*(T[4][3]-Tr);
                    Sf[5][2]= qq*(T[5][2]-Tr);
                    Sf[5][3]=q1*(T[5][3]-Tr);
                    Sf[5][4]=q2*(T[5][4]-Tr);
                    Sf[6][2]= qq*(T[6][2]-Tr);
                    Sf[6][3]=q1*(T[6][3]-Tr);
                    Sf[6][4]=q2*(T[6][4]-Tr);
                    Sf[6][5]=q3*(T[6][5]-Tr);
                    Sf[7][2]= qq*(T[7][2]-Tr);
                    Sf[7][3]=q1*(T[7][3]-Tr);
                    Sf[7][4]=q2*(T[7][4]-Tr);
                    Sf[8][2]= qq*(T[8][2]-Tr);
                    Sf[8][3]=q1*(T[8][3]-Tr);
                    Sf[9][2]= qq*(T[9][2]-Tr);
                    Sf[10][2]= qq*(T[10][2]-Tr);
                    r=((j-1)*dr)+(0.5 * dr);
                    KE= KA(Ko,T[i][j+1]);
                    KW= KA(Ko,T[i][j-1]);
                    KP= KA(Ko,T[i][j]);
                    KN= KA(Ko,T[i+1][j]);
                    KS= KA(Ko,T[i-1][j]);
                    AE= dt/dr*((KE-KW)/(4*dr)+KP/(2*r)+KP/dr);
                    AW= dt/dr*(-(KE-KW)/(4*dr)-KP/(2*r)+KP/dr);
                    AN= dt/(4*(dz*dz))*(KN-KS+4*KP);
                    AS= dt/(4*(dz*dz))*(-KN+KS+4*KP);
                    APO= -(2*dt*KP*(((1/dr)*(1/dr))+((1/dz)*(1/dz))));
                    PME=POT(T[i][j+1]);
                    PMW=POT(T[i][j-1]);
                    PMP=POT(T[i][j]);
                    PMN=POT(T[i+1][j]);
                    PMS=POT(T[i-1][j]);
                    TN[i][j]=(AE*PME+AW*PMW+AN*PMN+AS*PMS+APO*PMP)+(KN-KS)/(2*dz)+T[i][j]-Sf[i][j];
                } //end do for do j

                TN[i][1]= TN[i][2]; // CONDIO DE FRONTEIRA EM r=R, isolamento
                TN[i][L]= TN[i][L-1]; // CONDIO DE FRONTEIRA EM r=R, isolamento

            }//end do for do i
            for (int j1=1; j1<=L; j1++)  // condio de fronteira em z=h, isolamento
            {
                TN[M][j1]= TN[M-1][j1];
            }
            for (int i1=2; i1<=L; i1++)     //envelhecimento da TN
            {
                for (int j1=1; j1<=M; j1++)
                {
                    T[i1][j1]= TN[i1][j1];
                }
            }
//-------PROBLEMA INVERSO-----------
            if (fabs(te[kk][1]-10) <= dt)  //10 horas
            {
                SQE10=(T1[1][2]-T[1][2])*(T1[1][2]-T[1][2])+
                      (T1[1][5]-T[1][5])*(T1[1][5]-T[1][5])+(T1[1][8]-T[1][8])*(T1[1][8]-T[1][8])+
                      (T1[3][2]-T[3][2])*(T1[3][2]-T[3][2])+(T1[3][5]-T[3][5])*(T1[3][5]-T[3][5])+
                      (T1[3][8]-T[3][8])*(T1[3][8]-T[3][8])+(T1[6][2]-T[6][2])*(T1[6][2]-T[6][2])+
                      (T1[6][5]-T[6][5])*(T1[6][5]-T[6][5])+(T1[6][8]-T[6][8])*(T1[6][8]-T[6][8])+
                      (T1[11][2]-T[11][2])*(T1[11][2]-T[11][2])+(T1[11][5]-T[11][5])*(T1[11][5]-T[11][5])+
                      (T1[11][8]-T[11][8])*(T1[11][8]-T[11][8]);
            }
            if (fabs(te[kk][1]-20) <= dt)  //20 horas
            {
                SQE20=(T2[1][2]-T[1][2])*(T2[1][2]-T[1][2])+
                      (T2[1][5]-T[1][5])*(T2[1][5]-T[1][5])+(T2[1][8]-T[1][8])*(T2[1][8]-T[1][8])+
                      (T2[3][2]-T[3][2])*(T2[3][2]-T[3][2])+(T2[3][5]-T[3][5])*(T2[3][5]-T[3][5])+
                      (T2[3][8]-T[3][8])*(T2[3][8]-T[3][8])+(T2[6][2]-T[6][2])*(T2[6][2]-T[6][2])+
                      (T2[6][5]-T[6][5])*(T2[6][5]-T[6][5])+(T2[6][8]-T[6][8])*(T2[6][8]-T[6][8])+
                      (T2[11][2]-T[11][2])*(T2[11][2]-T[11][2])+(T2[11][5]-T[11][5])*(T2[11][5]-T[11][5])+
                      (T2[11][8]-T[11][8])*(T2[11][8]-T[11][8]);
            }
            if (fabs(te[kk][1]-29) <= dt)  //30 horas
            {
                SQE30=(T3[1][2]-T[1][2])*(T3[1][2]-T[1][2])+
                      (T3[1][5]-T[1][5])*(T3[1][5]-T[1][5])+(T3[1][8]-T[1][8])*(T3[1][8]-T[1][8])+
                      (T3[3][2]-T[3][2])*(T3[3][2]-T[3][2])+(T3[3][5]-T[3][5])*(T3[3][5]-T[3][5])+
                      (T3[3][8]-T[3][8])*(T3[3][8]-T[3][8])+(T3[6][2]-T[6][2])*(T3[6][2]-T[6][2])+
                      (T3[6][5]-T[6][5])*(T3[6][5]-T[6][5])+(T3[6][8]-T[6][8])*(T3[6][8]-T[6][8])+
                      (T3[11][2]-T[11][2])*(T3[11][2]-T[11][2])+(T3[11][5]-T[11][5])*(T3[11][5]-T[11][5])+
                      (T3[11][8]-T[11][8])*(T3[11][8]-T[11][8]);
            }
        } //end do for do kk

        double menor_erro = SQE10+SQE20+SQE30;

        if(menor_erro>0.0){
            qot=q;
            ero = menor_erro;
            
        mainProxy.retorno(qot,ero);
    }
//CkPrintf("sou o chare %d -- esse ?meu ii %d -- esse ?o meu qot %f -- esse ?o ero %f\n\n",thisIndex,ii,qot,ero);
    //} //end do ii, Problema inverso
//CkPrintf("  sou o chare %d --  esse o meu qot %f -- esse ?o ero %f\n\n",thisIndex,qot,ero);
// melhor seria retornar as matrizes vetor_erro e vetor qot nteira para o main, onde ele trataria
// o qot para achar o menor e executar a solu?o otima.

//retornar vetor

    
}


double Irrigacao::KA(double x1, double x2)     // X1 ?O Ko    // X2 ?O TETA
{
    double y=0;
    double a=0.467; // coeficiente do Psi na equa?o do potencial
    double m=0.934; // expoente na equa?o do potencial
    double n=2/(1-m); // expoente na equa?o do potencial, Burdines
    double pow1,pow2,pow3;
    if(x2 <= 0)
        y=0;
    else
    {
        if (x2 <=1)
        {
//Bordines
            pow1 = 1- pow(x2,(1/m));
            pow2 = 1 - pow(pow1,m);
            pow3 = pow2*pow2;
            y = x1 * pow(x2,0.5) * pow3;
        }
        else
            y=x1;
    }
    return(y);
}

// FUN?O PARA CALCULAR O POTENCIAL MATRICIAL COM BASE NO TETA

double Irrigacao::POT(double x)   // X ?o teta
{
    double y=0;
    double a=0.674; //coeficiente do Psi na equa?o do potencial
    double m=0.768; // expoente na equa?o do potencial
    double n=2/(1-m); // expoente na equa?o do potencial, Burdines
    double pow1,pow2,pow3;
    if (x <=0)
        y=0.35;
    else
    {
        if (x <=1)
        {
            pow1 = pow(x,(-1/m))-1;
            pow2 = pow((pow1),1/n);
            y=-pow(10,(1/a*pow2)); // pot matricial
        }
        else
            y=0;
    }
    return(y);
}
// void Irrigacao::pup(PUP::er &i)
// {
//     i|qo;	
//     i|R;
//     i|h;
//     i|dt;
//     i|qM;
//     i|m;
//     i|a;
//     i|Ko;
//     i|Ts;
//     i|T0;
//     i|Tr;
//     i|T00;
//     i|Tsup;
//     i|SQE10;
//     i|SQE20;
//     i|SQE30;
//     i|S1;
//     i|S2;
//     i|S3;
//     i|Med;
//     i|SQT;
//     i|SQT1;
//     i|SQT2;
//     i|SQT3;
//     i|R2;
//     i|q;
//     i|qq;
//     i|q1;
//     i|q2;
//     i|q3;
//     i|r;
//     i|KE;
//     i|KW;
//     i|KP;
//     i|KN;
//     i|KS;
//     i|AE;
//     i|AW;
//     i|AN;
//     i|AS;
//     i|APO;
//     i|PME;
//     i|PMW;
//     i|PMP;
//     i|PMN;
//     i|PMS;
//     i|dq;
//     i|Menor;
//     i|qot;
//     i|ero;
//     i|dr;
//     i|dz;
//     i(T,L,M);
//     i(T1,L,M);
//     i(T2,L,M);
//     i(T3,L,M);
//     i(Sf,L,M);
//     i(TN,L,M);
//     i(To,L,M);
  
// }


#include "Irrigacao.def.h"
