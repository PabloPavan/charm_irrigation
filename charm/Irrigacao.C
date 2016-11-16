#include "Irrigacao.decl.h"
#include "Irrigacao.h"
#include "main.decl.h"
#include <math.h>

extern /* readonly */ CProxy_Main mainProxy;
extern /* readonly */ int numChares; 


Irrigacao::Irrigacao () { }
Irrigacao::Irrigacao (CkMigrateMessage *msg) { } 


void Irrigacao::worker (int emissor, double evap1, double evap2, int pos_ini, int pos_fim, int tamanho) {
//--------DEFINIÇÃO DA MALHA ----------
const int L=128; // no. de pontos em r, varia com i
const int M= L; 
int nn=100;  //iteraes temporais, varia com k
int j = 0;
int iot = 0;
double R=0.15;   // raio do tubo,m
double h=0.33;   //altura do solo,m
double  dr=R/(L-1);
double  dz=h/(M-1);
double dt=0.3; // horas  
double Tr=0.01;
double T00; 
double T0 = 0.65;  
double Ts=0.76;
double qM = 0.09;
double tempo;  

//-----------curva de reteno de ua -----------
double m=0.934;
double a=0.467; //%0.674;%0.526;%;  % coeficiente do Psi na equao do potencial */
double n;  
double Ko=0.000004; //condutividade hidrlica de saturao
double T[L][M];
double T1[L][M];
double T2[L][M];
double T3[L][M];
double Sf[L][M];
double TN[L][M];
double te[100][1];
double erro[60];
double vqot[60];
double qo = 0.035;
double Menor = 100000000;
double ero = 0;
double Tsup = 0;
double SQE10 = 0;
double SQE20 = 0;
double SQE30 = 0;
double S1 = 0; 
double S2 = 0; 
double S3 = 0; 
double Med = 0; 
double SQT = 0; 
double SQT1 = 0; 
double SQT2 = 0; 
double SQT3 = 0; 
double R2 = 0;
double pow1 = 0; 
double pow2 = 0; 
double pow3 = 0;
double q = 0;
double qq = 0;
double qot = 0;
double q1 = 0;
double q2 = 0;
double q3 = 0;
double r = 0;
double KE = 0;
double KW = 0;
double KP = 0;
double KN = 0;
double KS = 0;
double AE = 0;
double AW = 0;
double AN = 0;
double AS = 0;
double APO = 0;
double PME = 0;
double PMW = 0;
double PMP = 0;
double PMN = 0;
double PMS = 0;
double menor_erro = 0;
double x[2][1];
double To[L][M];
double vfinal[numChares];
int cont=0;

int j0, j1, j2, kk, i, i1, jj, ii;  

int posi = 0;
double dq;
T00=(T0-Tr)/(Ts-Tr); //teor de umidade inicial adimensional
tempo=nn*dt;
dq=(qM-qo)/59; 
n=2/(1-m);

CkPrintf("\"Executado no  chare %d no PE %d (pedido pelo chare %d) = %d -- %d .\n", thisIndex, CkMyPe(), emissor, pos_ini, pos_fim );



for (j0=1; j0<M; j0++){
	for (i=1; i<L; i++){
	T[i][j0]=T00;  //condio inicial para toda a malha
}
} 

//---t = 0 h -------
To[1][2]=T00; To[1][5]=T00; To[1][8]=T00;
To[3][2]=T00; To[3][5]=T00; To[3][8]=T00;
To[6][2]=T00; To[6][5]=T00; To[6][8]=T00;
To[11][2]=T00; To[11][5]=T00; To[11][8]=T00;
//---t = 10 h -------
T1[1][2]=0.75*T00; T1[1][5]=0.75*T00; T1[1][8]=0.75*T00;
T1[3][2]=0.78*T00; T1[3][5]=0.8*T00; T1[3][8]=0.8*T00;
T1[6][2]=0.7*T00; T1[6][5]=0.8*T00; T1[6][8]=0.9*T00;
T1[11][2]=0.98*T00; T1[11][5]=0.85*T00; T1[11][8]=0.95*T00;
//---t = 20 h -------
T2[1][2]=0.5*T00; T2[1][5]=0.5*T00; T2[1][8]=0.5*T00;
T2[3][2]=0.65*T00; T2[3][5]=0.7*T00; T2[3][8]=0.75*T00;
T2[6][2]=0.45*T00; T2[6][5]=0.7*T00; T2[6][8]=0.8*T00;
T2[11][2]=0.97*T00; T2[11][5]=0.8*T00; T2[11][8]=0.95*T00;
//---t = 30 h -------
T3[1][2]=0.3*T00; T3[1][5]=0.3*T00; T3[1][8]=0.35*T00;
T3[3][2]=0.7*T00; T3[3][5]=0.6*T00; T3[3][8]=0.75*T00;
T3[6][2]=0.6*T00; T3[6][5]=0.6*T00; T3[6][8]=0.75*T00;
T3[11][2]=0.96*T00; T3[11][5]=0.75*T00; T3[11][8]=0.9*T00;

//------------PROBLEMA INVERSO E DIRETO---------------------

double vetor_erro[tamanho];
double vetor_qot[tamanho];

for (ii=pos_ini; ii < pos_fim; ii++){  // contador dos chutes do PI
	q=qo+(ii-1)*dq;
	for (j1=1; j1<M; j1++){
		for (i=1; i<L; i++){
			T[i][j1]=T00;  //condio inicial para toda a malha 
		}        
	}
	for (j2=1; j2<L; j2++){
		for (i=1; i<M; i++) {
		Sf[i][j2]=0;  //fonte zero para toda a malha 
	}
}
for (kk=1; kk<=nn; kk++){   //TEMPORAL
	te[kk][1]=(kk-1)*dt;
	qq=q*exp(-0.05*((te[kk][1]-12)*(te[kk][1]-12))); 
	for (i=2; i<=(L-1); i++){
		Tsup=evap1*te[kk][1]+evap2; //teta em z=0 pela evaporao 
		for (i1=1; i1<L; i1++){
			T[1][i1]=Tsup; //condio de fronteira em z=0                          
		}
		for (j=2; j<=(M-1); j++){                       
//------------FONTE = TRANSPIRAO ----------------
			q1=qq;
			q2=qq;
			q3=qq;
			Sf[2][2]= qq*(T[2][2]-Tr); Sf[3][2]= qq*(T[3][2]-Tr);   
			Sf[4][2]= qq*(T[4][2]-Tr); Sf[4][3]=q1*(T[4][3]-Tr);
			Sf[5][2]= qq*(T[5][2]-Tr); Sf[5][3]=q1*(T[5][3]-Tr); Sf[5][4]=q2*(T[5][4]-Tr);
			Sf[6][2]= qq*(T[6][2]-Tr); Sf[6][3]=q1*(T[6][3]-Tr);
			Sf[6][4]=q2*(T[6][4]-Tr);Sf[6][5]=q3*(T[6][5]-Tr);
			Sf[7][2]= qq*(T[7][2]-Tr); Sf[7][3]=q1*(T[7][3]-Tr); Sf[7][4]=q2*(T[7][4]-Tr);
			Sf[8][2]= qq*(T[8][2]-Tr); Sf[8][3]=q1*(T[8][3]-Tr);
			Sf[9][2]= qq*(T[9][2]-Tr); Sf[10][2]= qq*(T[10][2]-Tr);
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
for (j1=1; j1<L; j1++){ // condio de fronteira em z=h, isolamento
	TN[M][j1]= TN[M-1][j1];    
}
for (i1=2; i1<L; i1++){    //envelhecimento da TN
	for (j1=1; j1<M; j1++){
		T[i1][j1]= TN[i1][j1];   
	}
}
//-------PROBLEMA INVERSO-----------                             
if (fabs(te[kk][1]-10) <= dt){ //10 horas     
	SQE10=(T1[1][2]-T[1][2])*(T1[1][2]-T[1][2])+
	(T1[1][5]-T[1][5])*(T1[1][5]-T[1][5])+(T1[1][8]-T[1][8])*(T1[1][8]-T[1][8])+
	(T1[3][2]-T[3][2])*(T1[3][2]-T[3][2])+(T1[3][5]-T[3][5])*(T1[3][5]-T[3][5])+
	(T1[3][8]-T[3][8])*(T1[3][8]-T[3][8])+(T1[6][2]-T[6][2])*(T1[6][2]-T[6][2])+
	(T1[6][5]-T[6][5])*(T1[6][5]-T[6][5])+(T1[6][8]-T[6][8])*(T1[6][8]-T[6][8])+
	(T1[11][2]-T[11][2])*(T1[11][2]-T[11][2])+(T1[11][5]-T[11][5])*(T1[11][5]-T[11][5])+
	(T1[11][8]-T[11][8])*(T1[11][8]-T[11][8]);    
}
if (fabs(te[kk][1]-20) <= dt){ //20 horas
	SQE20=(T2[1][2]-T[1][2])*(T2[1][2]-T[1][2])+
	(T2[1][5]-T[1][5])*(T2[1][5]-T[1][5])+(T2[1][8]-T[1][8])*(T2[1][8]-T[1][8])+
	(T2[3][2]-T[3][2])*(T2[3][2]-T[3][2])+(T2[3][5]-T[3][5])*(T2[3][5]-T[3][5])+
	(T2[3][8]-T[3][8])*(T2[3][8]-T[3][8])+(T2[6][2]-T[6][2])*(T2[6][2]-T[6][2])+
	(T2[6][5]-T[6][5])*(T2[6][5]-T[6][5])+(T2[6][8]-T[6][8])*(T2[6][8]-T[6][8])+
	(T2[11][2]-T[11][2])*(T2[11][2]-T[11][2])+(T2[11][5]-T[11][5])*(T2[11][5]-T[11][5])+
	(T2[11][8]-T[11][8])*(T2[11][8]-T[11][8]);    
}
if (fabs(te[kk][1]-29) <= dt){ //30 horas
	SQE30=(T3[1][2]-T[1][2])*(T3[1][2]-T[1][2])+
	(T3[1][5]-T[1][5])*(T3[1][5]-T[1][5])+(T3[1][8]-T[1][8])*(T3[1][8]-T[1][8])+
	(T3[3][2]-T[3][2])*(T3[3][2]-T[3][2])+(T3[3][5]-T[3][5])*(T3[3][5]-T[3][5])+
	(T3[3][8]-T[3][8])*(T3[3][8]-T[3][8])+(T3[6][2]-T[6][2])*(T3[6][2]-T[6][2])+
	(T3[6][5]-T[6][5])*(T3[6][5]-T[6][5])+(T3[6][8]-T[6][8])*(T3[6][8]-T[6][8])+
	(T3[11][2]-T[11][2])*(T3[11][2]-T[11][2])+(T3[11][5]-T[11][5])*(T3[11][5]-T[11][5])+
	(T3[11][8]-T[11][8])*(T3[11][8]-T[11][8]);  
}
} //end do for do kk
vetor_erro[posi] = SQE10+SQE20+SQE30;
vetor_qot[posi] = q;
posi++;

} //end do ii, Problema inverso 
//retornar vetor
// MPI_Send(vetor_erro, tamanho, MPI_DOUBLE, 0, 10, MPI_COMM_WORLD);
// MPI_Send(vetor_qot, tamanho, MPI_DOUBLE, 0, 10, MPI_COMM_WORLD);

int iv;
for (iv = 0; iv < tamanho; iv++){
	menor_erro = vetor_erro[iv];      
	if(menor_erro < Menor){       
		qot = vetor_qot[iv];
		Menor = menor_erro;
		ero = menor_erro;
	}
	else{
		Menor = Menor;
	}
}

vfinal[cont]= qot;
cont++;

if(thisIndex == numChares-1){
	double menor=0;
	for(i=0; i<cont;i++){
		if(menor==0) menor=vfinal[i];
		if(menor>vfinal[i]) menor=vfinal[i];	
	}

	mainProxy.retorno(menor);

//mainProxy.terminado();
}

}
double Irrigacao::KA(double x1, double x2){    // X1 É O Ko    // X2 É O TETA
	double y=0;
double a=0.467; // coeficiente do Psi na equação do potencial 
double m=0.934; // expoente na equação do potencial 
double n=2/(1-m); // expoente na equação do potencial, Burdines 
double pow1,pow2,pow3;
if(x2 <= 0)
	y=0;
else{
	if (x2 <=1){
//Bordines
		pow1 = pow(1-x2,(1/m));          
		pow2 = pow(1 - pow1,m);
		pow3 = pow(0.5 * pow2, 2);
		y = pow(x1*x2, pow3);
	}
	else
		y=x1;
}
return(y);      
}

// FUNÇÃO PARA CALCULAR O POTENCIAL MATRICIAL COM BASE NO TETA

double Irrigacao::POT(double x){  // X é o teta
	double y=0;
double a=0.674; //coeficiente do Psi na equação do potencial 
double m=0.768; // expoente na equação do potencial 
double n=2/(1-m); // expoente na equação do potencial, Burdines 
double pow1,pow2,pow3;
if (x <=0)
	y=0.35;
else{      
	if (x <=1){
		pow1 = (pow(x,(-1/m))-1);
		pow2 = pow(((1/a)*pow1),1/n);
y=pow(-10,pow2); // pot matricial 
}
else
	y=0;
}
return(y);
}



#include "Irrigacao.def.h"
