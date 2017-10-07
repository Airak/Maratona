#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

#define NAO_VISITADO 0
#define VISITADO 1

vector <vector<int> > ladj;
vector <int> visitado;
queue <int> fila;

void BFS(int S, int nVertices);

int dif, nVertices, S, V, qtdeDeBuscas, tmp;	

int main(){

	while(scanf("%d", &nVertices)){
	
		/*Recebe o número de vértices*/
		if(nVertices==0)
			break;
		
		ladj.clear();
		ladj.resize(nVertices+1);		
			
		while(scanf("%d", &S)){
				
			/*Recebe o vértice de origem*/
			if(S==0)
				break;				
			
			while(scanf("%d", &V)){		
			
				/*Faz as listas de vértices*/
				if(V==0)
					break;			
				ladj[S].push_back(V);			
			
			}
		}
		
		scanf("%d", &qtdeDeBuscas);
		
		while(qtdeDeBuscas--){
			
			scanf("%d", &S);
			dif=0;		
			
			BFS(S, nVertices);
			
			for(int i=1; i<=nVertices; i++)
				if(visitado[i]==NAO_VISITADO)
					dif++;
			
			printf("%d", dif);
			
			for(int i=1; i<=nVertices; i++)
				if(visitado[i]==NAO_VISITADO)
					printf(" %d", i);				
			printf("\n");		
		
		}	
	}
	
	return 0;

}

void BFS (int S, int nVertices){
	

	fila.push(S);
	
	visitado.clear();
	visitado.resize(nVertices+1, NAO_VISITADO);
	/*Como eu não sei se consigo chegar no próprio vértice eu não o marco como visitado inicialmente*/
	
	while(!fila.empty()){
	
		/*Recebe o primeiro elemento da fila e o remove*/
		tmp=fila.front();	
		fila.pop();	
			
		for(int i=0; i<ladj[tmp].size(); i++){
		
			if(visitado[ladj[tmp][i]]==NAO_VISITADO){
			
				fila.push(ladj[tmp][i]);
				visitado[ladj[tmp][i]]=VISITADO;
			}
		}
	}
}


