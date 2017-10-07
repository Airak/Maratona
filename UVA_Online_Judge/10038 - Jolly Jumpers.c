#include<stdio.h>
#include<stdlib.h>
#define MAX 3000

int main(){

	int qtde, i, temp, new_qtde, verifica, x;
	int vet[MAX], aux[MAX-1];
	
	while(scanf("%d", &qtde)==1){
		
		i=0;
		verifica=1;
		while(i<qtde){/*Pega os valores*/
		
			scanf("%d", &vet[i]);
			aux[i]=0;
			i++;
						
		}
		
		new_qtde=qtde-1;
		
		for(i=0; i<qtde-1; i++){/*Calcula das diferenças*/
			temp=vet[i]-vet[i+1];
			if(temp<0)
				temp=temp*-1;
			aux[temp]=1;
		}
		
		for(i=1; i<qtde; i++){
			if(aux[i]==0){
				verifica=0;
				break;
			}
			continue;	
		}
		
		if(verifica==1)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}


	return 0;
}