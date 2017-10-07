#include<stdio.h>
#include<stdlib.h>
#define MAX 3000
 
int main(){
 
        int qtde, aux, soma, media, mov,i, cont=1;
        int vet[MAX];
 
        while((scanf("%d", &qtde)==1) && (qtde!=0)){
       
                aux=soma=mov=0;
               
                while(aux<qtde){
               
                        scanf("%d", &vet[aux]);
                        soma+=vet[aux];
                        aux++;
                       
                }
               
                media=soma/qtde;               
               
                for(i=0; i<qtde;i++)           
                        while(vet[i]>media){
                       
                                vet[i]--;
                                mov++;
                        }
                                       
                printf("Set #%d\n", cont);
                printf("The minimum number of moves is %d.\n\n", mov);
                cont++;
        }
       
        return 0;
}