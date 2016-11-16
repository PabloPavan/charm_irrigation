#include "main.decl.h"
#include "main.h"
#include "Irrigacao.decl.h"
//#include <iostream>
//using namespace std;
//#define L 16
//#define M L


/* readonly */ CProxy_Main mainProxy;
/* readonly */ int numChares;



Main::Main (CkArgMsg* msg) {
	
	numChares = 6;
	if (msg->argc > 1)
		numChares = atoi (msg->argv[1]);
	delete msg;
	CkPrintf ("Rodando o programa \"Irrigacao\" com %d chares em %d unidades de processamento.\n", numChares, CkNumPes());

//--------DEFINIÇÃO DA MALHA ----------

const int	L=128; // no. de pontos em r, varia com i
const int	M=L; 
int nn=100;  //iteraes temporais, varia com k
int nc = 60;  //nmero de q testados
int tamanho = 0;
double T00;	



// EVAPORACAO //

int tt[4][1];
double TEv[4][1],
A[4][2],
A2[2][2],
mataux[2][4],
mat1[2][4],
mat2[2][2],
mat3[2][4],
x[2][1];
double valor=0;
double linha1[4];
double linha2[4];
double laux[4];
double soma=0, soma1=0, soma2=0;
int nump=4; // nmero de pontos
int i,z,y0,y1,y2,y3,y4,y5,y6,y7,y8,y9,y10,y11,y12,y13;	
tt[1][1]=0;
tt[2][1]=10;
tt[3][1]=20;
tt[4][1]=30;
TEv[1][1]=T00;
TEv[2][1]=0.75*T00;
TEv[3][1]=0.5*T00;
TEv[4][1]=0.3*T00;

for(i=1; i <=nump; i++){
	A[i][1]=tt[i][1];
	A[i][2]=1;
}
// x=inv(A'*A)*A'*TEv 
for (y0 = 1; y0 <=4; y0++){         
	for (z = 1; z <=2; z++){                    // tranposta de A'
		mat1[z][y0] = A[y0][z];
	mataux[z][y0] = A[y0][z];
}
}
	for (y1 = 1; y1 <=4; y1++){                       //
		soma = soma + (mat1[1][y1] * A[y1][1]);   //
	}                                                 //
	A2[1][1] = soma;                                  //
	soma = 0;                                         //
	for (y2 = 1; y2 <=4; y2++){                       //
		soma = soma + (mat1[1][y2] * A[y2][2]);   //
	}                                                 //
	A2[1][2] = soma;                                  // multiplicao de A'*A
	soma = 0;                                         //  A2 = (mat1 * A) 
	for (y3 = 1; y3 <=4; y3++){                       //
		soma = soma + (mat1[2][y3] * A[y3][1]);   //
	}                                                 //
	A2[2][1] = soma;                                  //
	soma = 0;                                         //
	for (y4 = 1; y4 <=4; y4++){                       //
		soma = soma + (mat1[2][y4] * A[y4][2]);   //
	}                                                 //
	A2[2][2] = soma;                                  //
	soma = 0;                                         //

// A SEGUIR MATRIZ INVERSA DE A2 E GRAVA EM MAT2
	linha1[0] = A2[1][1];
	linha1[1] = A2[1][2];
	linha1[2] = 1;
linha1[3] = 0;                           //definindo a malha
linha2[0] = A2[2][1];
linha2[1] = A2[2][2];
linha2[2] = 0;
linha2[3] = 1;
//1 regra - o valor de linha1[0] deverser 1 - capturar o valor e dividir linha1 por ele
valor = linha1[0];
linha1[0] = linha1[0] / valor;
linha1[1] = linha1[1] / valor;
linha1[2] = linha1[2] / valor;
linha1[3] = linha1[3] / valor;
//2 regra - zerar o valor de linha2[0] - capturar o valor e multiplicar por (-) ele
//toda a linha1 e somar com a linha2;
valor = linha2[0];
laux[0] = linha1[0] * (-valor);
laux[1] = linha1[1] * (-valor);
laux[2] = linha1[2] * (-valor);
laux[3] = linha1[3] * (-valor);
linha2[0] = laux[0] + linha2[0];
linha2[1] = laux[1] + linha2[1];
linha2[2] = laux[2] + linha2[2];
linha2[3] = laux[3] + linha2[3];
//3 regra - o valor de linha2[1] deverser 1 - capturar o valor e dividir linha2 por ele
valor = linha2[1];
linha2[0] = linha2[0] / valor;
linha2[1] = linha2[1] / valor;
linha2[2] = linha2[2] / valor;
linha2[3] = linha2[3] / valor;
//4 regra - zerar o valor de linha1[1] - capturar o valor e multiplicar por (-) ele
//toda a linha2 e somar com a linha1;
valor = linha1[1];
laux[0] = linha2[0] * (-valor);
laux[1] = linha2[1] * (-valor);
laux[2] = linha2[2] * (-valor);
laux[3] = linha2[3] * (-valor);
linha1[0] = laux[0] + linha1[0];
linha1[1] = laux[1] + linha1[1];
linha1[2] = laux[2] + linha1[2];
linha1[3] = laux[3] + linha1[3];
//GRAVANDO EM MAT2
mat2[1][1] = linha1[2];
mat2[1][2] = linha1[3];
mat2[2][1] = linha2[2];
mat2[2][2] = linha2[3];

//inv(A'*A)*A' ou seja mat2 * mat1
for (y5 = 1; y5 <=2; y5++){                              
	soma = soma + (mataux[y5][1] * mat2[y5][1]);     
}                                                    
mat3[1][1] = soma;                                    
soma = 0;                                            
for (y6 = 1; y6 <=2; y6++){                              
	soma = soma + (mataux[y6][2] * mat2[y6][1]);     
}                                                    
mat3[1][2] = soma;                                    
soma = 0;                                            
for (y7 = 1; y7 <=2; y7++){                              
	soma = soma + (mataux[y7][3] * mat2[y7][1]);     
}                                                    
mat3[1][3] = soma;                                    
soma = 0;                                                
for (y8 = 1; y8 <=2; y8++){                                   //    multiplicao
soma = soma + (mataux[y8][4] * mat2[y8][1]);          //    mat3 =inv(A'*A)*A' 
}                                                    
mat3[1][4] = soma;                                    
soma = 0;                                                
for (y9 = 1; y9 <=2; y9++){                              
	soma = soma + (mataux[y9][1] * mat2[y9][2]);     
}
mat3[2][1] = soma;                                    
soma = 0;                                                
for (y10 = 1; y10 <=2; y10++){                          
	soma = soma + (mataux[y10][2]*mat2[y10][2]); 
}                      
mat3[2][2] = soma;                                   
soma = 0;                                         
for (y11 = 1; y11 <=2; y11++){                
	soma = soma + (mataux[y11][3]*mat2[y11][2]);  
}                                                 
mat3[2][3] = soma;                                 
soma = 0;                                         
for (y12 = 1; y12 <=2; y12++){                
	soma = soma + (mataux[y12][4]*mat2[y12][2]); 
}                                                 
mat3[2][4] = soma;                                
soma = 0;                                         

//FINALIZANDO x = mat3 * TEv;
for (y13 = 1; y13 <=4; y13++){                    
	soma1 = soma1 + (mat3[1][y13]*TEv[y13][1]);      
	soma2 = soma2 + (mat3[1+1][y13]*TEv[y13][1]);    
}                                                 
x[1][1] = soma1;                                   
x[2][1] = soma2; 

// EVAPORACAO //


double evap1 = x[1][1];
double evap2 = x[2][1];
int pos_ini = 0;
int pos_fim = 0;
tamanho = int (nc / (numChares)); //tamanho do intervalo de chutes (chutes / processos)
double vetor_erro[tamanho];
double vetor_qot[tamanho];
int patual,ratual,zera,posm = 0, posi = 0;

mainProxy = thisProxy;

CProxy_Irrigacao IrrigacaoArray = CProxy_Irrigacao::ckNew (numChares);

for (patual = 0; patual < (numChares); patual++){
	pos_fim = tamanho + pos_fim;
	CkPrintf("Enviou para chare %d = %d -- %d\n", patual, pos_ini, pos_fim ); 
	if (patual < (numChares )){
		IrrigacaoArray[patual].worker(-1,evap1,evap2,pos_ini,pos_fim,tamanho);
	}

	pos_ini = pos_fim + 1;
}	
	//////mainProxy.terminado();
}

Main::Main (CkMigrateMessage* msg) { }


void Main::retorno(double err){


	CkPrintf("!ERROR MAIN %1f\n",err);
	CkExit ();
	
}
void Main::terminado () {
	CkExit ();
}

#include "main.def.h"
