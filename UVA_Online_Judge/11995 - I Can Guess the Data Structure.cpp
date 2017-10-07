#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int i, f, temp, p;

vector <he> heap;
stack <int> pilha;
queue <int> fila;

void desce (int p, int n){

	f= 2*p;
	
	while(p<=n/2){
	
		if(f<=n && heap[f]>heap[f+1]){
			f++;
			break;
		}
		if(heap[f]<=heap[p]){
			
			temp=heap[f];
			heap[f]=heap[p];
			heap[p]=temp;
			f=2*p;
	
		}
	}
}

void sobe (int f){

	p=f/2;
	
	while(f!=0 && heap[p]<heap[f]){
	
		temp=heap[p];
		heap[p]=heap[f];
		heap[f]=temp;
		f=p;
		p=f/2;
	}
}

void Constroi(){

	for(i=0; i<heap.size(); i++){
		sobe(i);
	}
}

void reset(){
	
	if(heap.size()>=1)
		while(heap.size()!=0)
			heap.erase(heap.begin());
	if(pilha.size()>=1)
		while(!pilha.empty())
			pilha.pop();
	if(fila.size()>=1)
		while(!fila.empty())
			fila.pop();
	
}

int main(){

	int n,x,y;

	while(scanf("%d", &n)==1){
	
		int vet[3] = {1,1,1};
		int cont=0;
		
		while(n--){
		
			scanf("%d %d", &x, &y);
			
			if(x==1){
				heap.push_back(y);
				Constroi();
				fila.push(y);
				pilha.push(y);		
			}
			else{
			
				if(vet[0]!=0)
					if(heap.size()>=1)
						if(y==heap[0]){
							vet[0]=1;
							heap.erase(heap.begin());
							Constroi();
						}
						else
							vet[0]=0;
					else
						vet[0]=0;
						
				if(vet[1]!=0)
					if(fila.size()>=1)
						if(y==fila.front()){
							vet[1]=1;
							fila.pop();	
						}
						else
							vet[1]=0;
					else
						vet[1]=0;
				
				
				if(vet[2]!=0)
					if(pilha.size()>=1)
						if(y==pilha.top()){
							vet[2]=1;
							pilha.pop();						
						}
						else
							vet[2]=0;
					else
						vet[2]=0;				
			}				
			
		}
		
		for(i=0; i<3; i++)
			if(vet[i]==1)
				cont++;
				
		if(cont==0)
			printf("impossible\n");
		else if(cont>1)
			printf("not sure\n");
			else{
				if(vet[0]==1)
					printf("priority queue\n");
				else if(vet[1]==1)
					printf("queue\n");
					else
						printf("stack\n");
			}
			
		reset();
		
	}
	return 0;
}
