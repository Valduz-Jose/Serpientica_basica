#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define arriba 72
#define abajo 80
#define derecha 77
#define izquierda 75
void imprimir (int matriz[30][30]);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	system("color e");
	int m[30][30],i,j;
	int serpf[30],serpc[30],act[30];
	char tecla=izquierda;
	int auxf,auxc,muerto=0,aux2f,aux2c;
	int frutf,frutc,hayfrut=0,cont=2,gan=0;
	srand(time(0));
	//imprimir la matriz :v
	for(i=0;i<30;i++){
		for(j=0;j<30;j++){
			if(i==0||j==0||i==29||j==29){
				m[i][j]=42;
			}else{
				m[i][j]=32;
			}
		}
	}
	//mi matriz =P
	
	
	
	serpf[0]=5; serpc[0]=5;
	serpf[1]=5; serpc[1]=6;
	
	for(i=0; i<30;i++){
		act[i]=0;
	}
	//aqui con el for desactivo a snake 
	act[0]=1; act[1]=1;
	//aqui activo solo la cabeza y un cuerpo
	m[serpf[0]][serpc[0]]=1;
	m[serpf[1]][serpc[1]]=4;
	
	//este es para borrar la cabeza por un instante;

	while(tecla!='x'){
		if(kbhit()){
			tecla=getch();
		}
		m[serpf[0]][serpc[0]]=32;
			for(i=0;i<30;i++){
			if(act[i]==1){
				m[serpf[i]][serpc[i]]=32;
			}
		}
		auxf=serpf[0]; auxc=serpc[0];
		//moviemientos xD
		if(tecla==arriba){
			serpf[0]--;
		}
		if(tecla==abajo){
			serpf[0]++;
		}
		if(tecla==derecha){
			serpc[0]++;
		}
		if(tecla==izquierda){
			serpc[0]--;
		}
		//este if es para muerto si es diferente de 32 q es espacio se muere con muerto q es bandera
		if(m[serpf[0]][serpc[0]]==42||m[serpf[0]][serpc[0]]==4){
			muerto=1;
			tecla='x';
			
		}else{
			for(i=1;i<30;i++){
				if(act[i]==1){
					aux2f=serpf[i]; aux2c=serpc[i];
					serpf[i]=auxf; serpc[i]=auxc;
					auxf=aux2f; auxc=aux2c;
				}
			}
			
		}
		m[serpf[0]][serpc[0]]=1;
		for(i=1;i<30;i++){
			if(act[i]==1){
				m[serpf[i]][serpc[i]]=4;
			}
		}
		if(hayfrut==0){
		 
		do{
			frutf=rand()%8+1;
			frutc=rand()%8+1;
		}while(m[frutf][frutc]!=32);
		hayfrut=1;
	}
	m[frutf][frutc]=3;
	if(m[serpf[0]][serpc[0]]==3){
		hayfrut=0;
		m[serpf[0]][serpc[0]]=1;
		act[cont]=1;
		serpf[cont]=auxf;
		serpc[cont]=auxc;
		m[serpf[cont]][serpc[cont]]=4;
		cont++;
	}
	if(cont==30){
		gan=1;
		tecla='x';
	}
	Sleep(200);
	system("CLS");
	imprimir(m);
	}//while
	if(muerto==1){
		printf("\n\t\tKill\n");
	}
	if(gan==1){
		printf("\n\t\tWINER!!\t\t\n");
	}
	
	return 0;
}

void imprimir (int matriz[30][30]){
	int i,j;
	printf("\n\t\t\t**SNAKE**");
	
	for(i=0;i<30;i++){
		
	printf("\n\t\t\t");
	
		for(j=0;j<30;j++){
			
			printf("%c",matriz[i][j]);
		}
	}	
	
}
