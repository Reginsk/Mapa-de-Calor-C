#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define TAM 15

struct teste{
	
	float cx;
	float cy;
	float u1[TAM][TAM];
	float u2[TAM][TAM];
	
};

void primeira_matriz(struct teste *rgb){
	
	rgb->cx = 0.1;
	rgb->cy = 0.1;

	int ix, iy;

	for (ix = 0; ix <= TAM -1; ix++) {
    	for (iy = 0; iy <= TAM -1; iy++){
    		rgb->u1[ix][iy] =  ix * (TAM - ix -1) * iy * (TAM - iy - 1);
      		rgb->u2[ix][iy] = 0;				
		} 
	}     


}

void carregar_m1(struct teste *rgb){
	
	int ix, iy;
	
	printf("Matriz inicial: \n\n");
	
	for (ix = 0; ix < TAM; ix++) {
    	for (iy = 0; iy < TAM; iy++) {
      
	  	printf("%.0f \t ", rgb->u1[ix][iy]);
      	    	
 		}
 		printf("\n");
 	}
 	
}

void att_matriz(struct teste *rgb){
	rgb->cx = 0.1;
	rgb->cy = 0.1;
	
	int ix, iy;

	printf("\n\nPrimeira atualização: \n\n");
   
    for (ix = 1; ix <= TAM -2; ix++) {
        for (iy = 1; iy <= TAM -2; iy++) {
        		
    		rgb->u2[ix][iy] =  rgb->u1[ix][iy]  +
    		rgb->cx * (rgb->u1[ix+1][iy] + rgb->u1[ix-1][iy] - 2. * rgb->u1[ix][iy]) +
    		rgb->cy * (rgb->u1[ix][iy+1] + rgb->u1[ix][iy-1] - 2. * rgb->u1[ix][iy]);

        }
    }	
}

void carregar_att(struct teste *rgb){
	rgb->cx = 0.1;
	rgb->cy = 0.1;
	
	int ix, iy;
	
	for (ix = 0; ix < TAM ; ix++) {
    	for (iy = 0; iy < TAM ; iy++) {
      	
			printf("%.0f \t ", rgb->u2[ix][iy]);
      	      	
 		}
 		printf("\n");	
	}	
}


void fogo(struct teste *rgb){
	rgb->cx=0.1;
	rgb->cy=0.1;
	
	int ix, iy;
	int i = 0;
	
	int sec = 0;
	
		while (i<2){
		
			if(sec == 1){
						
			    for (ix = 1; ix < TAM -1; ix++) {
			        for (iy = 1; iy < TAM -1; iy++) {
			     		        		
		        		rgb->u2[ix][iy] =  rgb->u2[ix][iy]  +
		        		rgb->cx * (rgb->u1[ix+1][iy] + rgb->u1[ix-1][iy] - 2. * rgb->u1[ix][iy]) +
		        		rgb->cy * (rgb->u1[ix][iy+1] + rgb->u1[ix][iy-1] - 2. * rgb->u1[ix][iy]);
		        		
		        		if(rgb->u2[ix][iy] < 0){
		        			rgb->u2[ix][iy] = 0;
						}
			        }
			      }
				
				for (ix = 0; ix < TAM ; ix++) {
			    	for (iy = 0; iy < TAM; iy++) {
			      	
						printf("%.0f \t ", rgb->u2[ix][iy]);
			      	      	
			 		}
			 		printf("\n");	
				}
				
			sec = -1;
			printf("\n");
			} 
		
			
			usleep(400000); //1 segundo
			sec++;
			
			if(rgb->u2[TAM/2][TAM/2] < 1){
				return ;
			}
			
		
		}
}

int main (){
	setlocale(LC_ALL, "Portuguese");
	struct teste rgb;

	struct teste *ref;	
		
	ref = (struct teste *) malloc(5 * sizeof(struct teste));
	
	if(ref == NULL){
		printf("Não foi possível alocar memória\n");
	}
	
	ref = &rgb;
	
	primeira_matriz(ref);
	carregar_m1(ref);
	att_matriz(ref);
	carregar_att(ref);
	fogo(ref);
}

