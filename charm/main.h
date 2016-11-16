#ifndef __MAIN_H__
#define __MAIN_H__

class Main : public CBase_Main {
 public:
 	
Main (CkArgMsg* msg);

Main (CkMigrateMessage* msg);

double KA(double x1, double x2);
double POT(double x);
void solucao(double qot);
void terminado();

 };
 #endif //__MAIN_H__