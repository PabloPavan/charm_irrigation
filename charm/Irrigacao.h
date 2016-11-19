#ifndef __Irrigacao_H__
#define __Irrigacao_H__
#define L 16
#define M 16
#define nc 60
#define nn 100
class Irrigacao : public CBase_Irrigacao
{

private:
//    Declaracao das variaveis de modo privado

    const double  qo = 0.035, R=0.15, h=0.33,dt=0.3,qM = 0.09, m=0.934, a=0.467, Ko=0.000004,
                  Ts=0.76,T0 = 0.65,Tr=0.01,T00=(T0-Tr)/(Ts-Tr);

    double Tsup,SQE10,SQE20,SQE30,S1,S2,S3,Med,SQT,SQT1,SQT2,SQT3,R2,
           q,qq,q1,q2,q3,r,KE,KW,KP,KN,KS,AE,AW,AN,AS,APO,PME,PMW,PMP,PMN,PMS,dq,Menor,qot,ero,te[100][1],
           dr=R/(L-1),dz=h/(M-1), T[L][M], T1[L][M], T2[L][M], T3[L][M], Sf[L][M], TN[L][M],To[L][M];
public:


    Irrigacao ();

    Irrigacao (CkMigrateMessage *msg);

    void worker(int emissor, double evap1, double evap2, int pos_ini, int pos_fim, int tamanho);
    double KA(double x1, double x2);
    double POT(double x);

};
#endif
