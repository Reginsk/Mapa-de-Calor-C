#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define TAM 15


typedef struct {	
	float cx;
	float cy;
	float u1[TAM][TAM];
	float u2[TAM][TAM];	
} Teste;

void carregar_m1(Teste*);
void mostrar_m1(Teste*);
void carregar_att(Teste*);
void mostrar_att(Teste*);
void printa(Teste*);
	
int main (){
	setlocale(LC_ALL, "Portuguese");	
	Teste *ref;	
	ref = (Teste *) malloc(sizeof(Teste));
	
	ref->cx=0.1;
	ref->cy=0.1;
			
	if(ref == NULL){
		printf("Não foi possível alocar memória\n");
	}
	
	carregar_m1(ref);
	mostrar_m1(ref);
	carregar_att(ref);
	mostrar_att(ref);
	printa(ref);
	free(ref);	
	return 0;
}

void carregar_m1(Teste *mat){	
	int ix, iy;
	for (ix = 0; ix < TAM; ix++) {
    	for (iy = 0; iy < TAM; iy++){
    		mat->u1[ix][iy] =  ix * (TAM - ix -1) * iy * (TAM - iy - 1);
      		mat->u2[ix][iy] = 0;				
		} 
	}     
}

void mostrar_m1(Teste *mat){	
	int ix, iy;	
	printf("Matriz inicial: \n\n");	
	for (ix = 0; ix < TAM; ix++) {
    	for (iy = 0; iy < TAM; iy++) {      
	  	printf("%.0f \t ", mat->u1[ix][iy]);    	    	
 		}
 		printf("\n");
 	}	
}

void carregar_att(Teste *mat){
	int ix, iy;   
    for (ix = 1; ix < TAM -1; ix++) {
        for (iy = 1; iy < TAM -1; iy++) {      		
    		mat->u2[ix][iy] =  mat->u1[ix][iy]  +
    		mat->cx * (mat->u1[ix+1][iy] + mat->u1[ix-1][iy] - 2. * mat->u1[ix][iy]) +
    		mat->cy * (mat->u1[ix][iy+1] + mat->u1[ix][iy-1] - 2. * mat->u1[ix][iy]);
        }
    }
}

void mostrar_att(Teste *mat){	
	int ix, iy;	
	for (ix = 0; ix < TAM ; ix++) {
    	for (iy = 0; iy < TAM ; iy++) {    	
			printf("%.0f \t ", mat->u2[ix][iy]);     	     			    	
 		}
 		printf("\n");	
	}
}

void u1(Teste *mat){	
	int ix, iy;
		for (ix = 0; ix < TAM ; ix++) {
			for (iy = 0; iy < TAM; iy++) {
				mat->u1[ix][iy] =  mat->u2[ix][iy];				
			if(mat->u2[ix][iy] < 0){
		        mat->u2[ix][iy] = 0;
			} 				
		}
	}
}

void printa(Teste *mat){		
	while(mat->u2[TAM/2][TAM/2] > 1){			
		u1(mat);
		carregar_att(mat);			
		mostrar_att(mat);	
		usleep(100000);			
	}		
}
