#ifndef __MAIN_H__
#define __MAIN_H__
#define L 64
#define M 64
#define nc 60
#define nn 100
class Main : public CBase_Main
{
private:
//    Declaracao das variaveis de modo privado
    int nump,tt[4][1],pos_ini,pos_fim,tamanho,patual,contador;

    float tempofinal,tempo1,tempo2;

    const double  qo = 0.035, R=0.15, h=0.33,dt=0.3,qM = 0.09, m=0.934, a=0.467, Ko=0.000004,
                  Ts=0.76,T0 = 0.65,Tr=0.01,T00=(T0-Tr)/(Ts-Tr);

    double n, tempo, valor, evap1,evap2,soma,soma1,soma2,Tsup,SQE10,SQE20,SQE30,S1,S2,S3,Med,SQT,SQT1,SQT2,SQT3,R2,
           q,qq,q1,q2,q3,r,KE,KW,KP,KN,KS,AE,AW,AN,AS,APO,PME,PMW,PMP,PMN,PMS,menor_erro,dq,Menor,
           TEv[4][1], A[4][2], A2[2][2], mataux[2][4], mat1[2][4], mat2[2][2], mat3[2][4], x[2][1], linha1[4],
           vfinal[100], efinal[100], linha2[4], laux[4],te[100][1],
           dr=R/(L-1),dz=h/(M-1),
           T[L][M], T1[L][M], T2[L][M], T3[L][M], Sf[L][M], TN[L][M],To[L][M];

public:

    Main (CkArgMsg* msg);

    Main (CkMigrateMessage* msg);

    double KA(double x1, double x2);
    double POT(double x);
    void retorno(double qot,double ero);
    void solucaoOtima(double ero, double qot);
    void terminado();

};
#endif //__MAIN_H__
