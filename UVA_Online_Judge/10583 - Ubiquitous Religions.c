#include<stdio.h>
#include<stdlib.h>
#define MAX 50003

int pai[MAX];
int tam[MAX];


void MakeSet(int n);
int find(int n);
int Union(int a, int b);
int conta(int n);
void quickSort(int valor[], int esquerda, int direita);

int main(){

	int n, l, Case=1, i, a, b;
	
	while(scanf("%d %d", &n, &l)==2){
		if( n==0 && l==0)
			break;
	
		for(i=1; i<=n; i++)
			MakeSet(i);
	
		while(l>0){
			
			scanf("%d %d", &a, &b);			
			Union(a,b);
			l--;
	
		}
		
		for(i=1; i<=n; i++)
			find(i);
					
		quickSort(pai, 1, n);
		printf("Case %d: %d\n", Case, conta(n));
		Case++;
	}

	return 0;

}

int conta(int n){

	int i, contador=1, aux;	
	aux=pai[1];
	for(i=2; i<=n; i++){
		if(aux!=pai[i]){
			aux=pai[i];
			contador++;
		}
	}
	return contador;

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


void MakeSet(int n){

	tam[n]=1;
	pai[n]=n;

}

int find(int n){

	if(pai[n]==n)
		return n;
		
	int temp = find(pai[n]);
	pai[n]=temp;
	return temp;

}

int Union(int a, int b){


	if(find(a)==find(b))
		return;
		
	if(tam[a]<tam[b]){
		pai[find(a)]=find(b);
		tam[b]+=tam[a];
	}
	else{
		pai[find(b)]=find(a);
		tam[a]+=tam[b];
	}

	return;

}
