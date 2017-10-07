#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

int i, f, temp, p;

vector <int> heap;

void sobe (int f){

	p=f/2;
	
	while(f!=0 && heap[p]>heap[f]){
	
		temp=heap[p];
		heap[p]=heap[f];
		heap[f]=temp;
		f=p;
		p=f/2;
	}
}

int Constroi(){

	for(i=0; i<heap.size(); i++){
		sobe(i);
	}
}

int main(){

	int c, aux, resp;
	
	while(scanf("%d", &c)==1 && c!=0){ 
	
		resp=0;	
		while(c--){
			
			scanf("%d", &aux);
			heap.push_back(aux);		
		}
		
		Constroi();
		
		while(heap.size()>1){
		
			aux=heap[0]+heap[1];
			heap.erase(heap.begin());
			heap.erase(heap.begin());
			
			resp+=aux;
			heap.push_back(aux);
			Constroi();		
		
		}
		
		heap.erase(heap.begin());
		printf("%d\n", resp);

	}
	return 0;
}
