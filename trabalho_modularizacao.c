#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define TAM 15

void primeira_matriz(int i){
	float cx = 0.1;
	float cy = 0.1;
	float u1[TAM][TAM], u2[TAM][TAM];
	int ix, iy;

	for (ix = 0; ix <= TAM -1; ix++) {
    	for (iy = 0; iy <= TAM -1; iy++){
    		u1[ix][iy] =  ix * (TAM - ix -1) * iy * (TAM - iy - 1);
      		u2[ix][iy] = 0;				
		} 
	}       
}


void carregar_m1(int i){
	float cx = 0.1;
	float cy = 0.1;
	float u1[TAM][TAM], u2[TAM][TAM];
	int ix, iy;
	
	printf("Matriz inicial: \n\n");
	
	for (ix = 0; ix < TAM; ix++) {
    	for (iy = 0; iy < TAM; iy++) {
      
	  	printf(" %.0f \t ", u1[ix][iy]);
      	    	
 		}
 		printf("\n");
 	}
}


void att_matriz(int i){
	float cx = 0.1;
	float cy = 0.1;
	float u1[TAM][TAM], u2[TAM][TAM];
	int ix, iy;

	printf("\n\nPrimeira atualização: \n\n");
   
    for (ix = 1; ix <= TAM -2; ix++) {
        for (iy = 1; iy <= TAM -2; iy++) {
        		
    		u2[ix][iy] =  u1[ix][iy]  +
    		cx * (u1[ix+1][iy] + u1[ix-1][iy] - 2. * u1[ix][iy]) +
    		cy * (u1[ix][iy+1] + u1[ix][iy-1] - 2. * u1[ix][iy]);

        }
    }      
}


void carregar_att(int i){
	float cx = 0.1;
	float cy = 0.1;
	float u1[TAM][TAM], u2[TAM][TAM];
	int ix, iy;
	
	for (ix = 0; ix < TAM ; ix++) {
    	for (iy = 0; iy < TAM ; iy++) {
      	
			printf(" %.0f \t ", u2[ix][iy]);
      	      	
 		}
 		printf("\n");	
	}
}


void fogo(int x){
	float cx = 0.1;
	float cy = 0.1;
	float u1[TAM][TAM], u2[TAM][TAM];
	int ix, iy;
	int i = 0;
	
	int sec = 0;
	
		while (i<2){
		
			if(sec == 1){
						
			    for (ix = 1; ix < TAM -1; ix++) {
			        for (iy = 1; iy < TAM -1; iy++) {
			     		        		
		        		u2[ix][iy] =  u2[ix][iy]  +
		        		cx * (u1[ix+1][iy] + u1[ix-1][iy] - 2. * u1[ix][iy]) +
		        		cy * (u1[ix][iy+1] + u1[ix][iy-1] - 2. * u1[ix][iy]);
		        		
		        		if(u2[ix][iy] < 0){
		        			u2[ix][iy] = 0;
						}
			        }
			      }
				
				for (ix = 0; ix < TAM ; ix++) {
			    	for (iy = 0; iy < TAM; iy++) {
			      	
						printf("%.0f \t ", u2[ix][iy]);
			      	      	
			 		}
			 		printf("\n");	
				}
				
			sec = -1;
	
			} 
			
			usleep(800000); //1 segundo
			sec++;
			
			if(u2[TAM/2][TAM/2] < 1){
				return ;
			}
			
			printf("\n");
		}
}


int main (){
	setlocale(LC_ALL, "Portuguese");

	int ref;	
		
	primeira_matriz(ref);
	carregar_m1(ref);
	att_matriz(ref);
	carregar_att(ref);
	fogo(ref);

}

