#ifndef __MAIN_H__
#define __MAIN_H__

class Main : public CBase_Main {
 public:
 	
Main (CkArgMsg* msg);

Main (CkMigrateMessage* msg);

void retorno(double err);
void terminado();

 };
 #endif //__MAIN_H__