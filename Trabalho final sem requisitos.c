// 1 - Mostrar a matriz inicial, antes de atualizar.
// 2 - Mostrar para cada atualização que representa o esfriamento com o passar do tempo.
// 3 - Funções de iniciar matriz, escrever , etc.
// 4 - cx e cy são constante, 0.1 ou 0.01 no valor delas.

#include <locale.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h> //   #include <unistd.h>
#define TAM 40

int main (){
	setlocale(LC_ALL, "Portuguese");
	
	int nx = 15, ny = 15;
	float cx = 0.1;
	float cy = 0.1;
	float u1[TAM][TAM], u2[TAM][TAM];
	int ix, iy;
	
	
//inicia matriz

   for (ix = 0; ix <= nx; ix++) 
      for (iy = 0; iy <= ny; iy++) 
        u1[ix][iy] =  ix * (nx - ix -1) * iy * (ny - iy - 1);

	for (ix = 0; ix < nx; ix++) {
    	for (iy = 0; iy < ny; iy++) {
      	printf(" %.0f \t ", u1[ix][iy]);
      	    	
 		}
 		printf("\n");
 	}
//fim matriz

//inicio atualiza
    for (ix = 1; ix <= nx-2; ix++) {
        for (iy = 1; iy <= ny-2; iy++) {
        	u2[ix][iy] =  u1[ix][iy]  +
        	cx * (u1[ix+1][iy] + u1[ix-1][iy] - 2. * u1[ix][iy]) +
        	cy * (u1[ix][iy+1] + u1[ix][iy-1] - 2. * u1[ix][iy]);
        	
        	//cx * (u1(ix+1,iy) + u1(ix-1,iy) - 2.*u1(ix,iy)) +
           //cy * (u1(ix,iy+1) + u1(ix,iy-1) - 2.*u1(ix,iy))
         }
      }
	
	for (ix = 0; ix < nx; ix++) {
    	for (iy = 0; iy < ny; iy++) {
      	
			printf(" %.0f \t ", u2[ix][iy]);
      	      	
 		}
 		printf("\n");	
	}
//fim atualiza	



//FOGO!!! 
//outro atualiza
int i = 0;
int sec = 0;

	while (i<6){
		printf(" %i,", sec);
		if(sec == 1){
					
		    for (ix = 1; ix <= nx-2; ix++) {
		        for (iy = 1; iy <= ny-2; iy++) {
		        	u2[ix][iy] =  u2[ix][iy]  +
		        	cx * (u1[ix+1][iy] + u1[ix-1][iy] - 2. * u1[ix][iy]) +
		        	cy * (u1[ix][iy+1] + u1[ix][iy-1] - 2. * u1[ix][iy]);
		        
					if(u2[ix][iy] < 0){
						u2[ix][iy] = 0;
					}
		         }
		      }
			
			for (ix = 0; ix < nx; ix++) {
		    	for (iy = 0; iy < ny; iy++) {
		      	
					printf("%.0f \t ", u2[ix][iy]);
		      	      	
		 		}
		 		printf("\n");	
			}
			
		sec=-1;

		} 
		
		Sleep(200); //   usleep(100000);


		sec++;
	}
}
