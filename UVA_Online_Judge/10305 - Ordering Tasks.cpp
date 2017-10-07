#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAX 101
#define NAO_VISITADO 0
#define VISITADO 1

vector<int> ladj[MAX];
vector<int> visitado;
list<int> tasks;

void busca_profundidade(int, int);

int main(){

	int n, m;   /*n - tarefas & m - depen.*/
	
	while(scanf("%d %d", &n, &m)){/*Recebe o número de tarefas (n) a serem feitas e o número de tarefas dependentes de outras (m)*/
	
	    visitado.assign(101, 0); //substitui o memset pra vectors
	    
		if(n==0 && m==0)
			break;
			
		for(int i = 0; i<m; i++){
		
			int x, y;			
			scanf("%d %d", &x, &y);/* Tarefa mestre -> Tarefa escrava*/	
		
			ladj[x].push_back(y);/* Adiciona escravo na lista ao final da lista de tarefas dependentes do mestre*/
		}
		
		for(int i = 1; i <= n; ++i)
			busca_profundidade(i, n);
		    
		for(list<int>::iterator it = tasks.begin(); it != tasks.end(); ++it)
		    cout << *it << " ";
	    cout << endl;
	    
	    tasks.clear();
	    for(int i = 0; i < n; i++)
	        ladj[i].clear();
	}

	return 0;
}


void busca_profundidade (int vertice, int numVert){

	visitado[vertice]=VISITADO; 
	
	for(vector<int>::iterator it = ladj[vertice].begin(); it != ladj[vertice].end(); ++it) {
        	
	    int v = *it;
	    
		if(visitado[v] == NAO_VISITADO){
			// Ou seja, se o vértice determinado ainda não foi visitado
			busca_profundidade(v, numVert);
		}
	} 
    	
	if(find(tasks.begin(), tasks.end(), vertice) == tasks.end()){
	    tasks.push_front(vertice);
	}
}
