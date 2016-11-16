#ifndef __Irrigacao_H__
#define __Irrigacao_H__

class Irrigacao : public CBase_Irrigacao
{
 public:


Irrigacao ();

Irrigacao (CkMigrateMessage *msg);

void worker(int emissor, double evap1, double evap2, int pos_ini, int pos_fim, int tamanho);
double KA(double x1, double x2);
double POT(double x);

};
 #endif 