#include<stdio.h>
#include<stdlib.h>

void quickSort(int valor[], int esquerda, int direita);

int main (){

	int t, n, x, i, j, store[20];
	
	scanf("%d", &t);
	
	for(i = 0; i<t; i++){
		
		scanf("%d", &n);
		
		for(j=0; j<n; j++){
			 scanf("%d", &store[j]);
		}
		
		quickSort(store, 0, n-1);
		
		x = ( store[n-1] - store [0] )*2;
		printf("%d\n", x);
	}


}

void quickSort(int valor[], int esquerda, int direita)
{
    int i, j, x, y;
    i = esquerda;
    j = direita;
    x = valor[(esquerda + direita) / 2];
 
    while(i <= j)
    {
        while(valor[i] < x && i < direita)
        {
            i++;
        }
        while(valor[j] > x && j > esquerda)
        {
            j--;
        }
        if(i <= j)
        {
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if(j > esquerda)
    {
        quickSort(valor, esquerda, j);
    }
    if(i < direita)
    {
        quickSort(valor,  i, direita);
    }
}
