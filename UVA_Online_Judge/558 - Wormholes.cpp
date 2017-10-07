#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <list>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define INFINITO 9999999
#define MAX 3000

typedef struct Aresta{
	int u;
	int v;
	int peso;
} aresta;

void Bellman();

aresta arestas[MAX];
int d[MAX];

int n,m,c,t, x, y;

int main(){

	scanf("%d", &c);
	
	while(c--){

		scanf("%d %d", &n, &m); 
		
		for(int i=0; i<m; i++){
		
			scanf("%d %d %d", &x, &y, &t);
			arestas[i].u=x;
			arestas[i].v=y;
			arestas[i].peso=t;
		
		}
		
		Bellman();
	}
	return 0;
}

void Bellman(){

    for(int i=0; i <= n; i++)
        d[i]=INFINITO;
         
    d[0]=0;
     
    for(int i=0; i < n-1; i++) {
        for(int j=0; j < m; j++) {
            if( d[ arestas[j].v ] > d[ arestas[j].u ] + arestas[j].peso ) {
                 d[ arestas[j].v ] = d[ arestas[j].u ] +arestas[j].peso;
            }
        }
    }
    
	for(int j=0; j < m; j++) {
	    if( d[ arestas[j].v ] > d[ arestas[j].u ] + arestas[j].peso ) {
	    	printf ("possible\n");
	    	return;
	    }       
	}
	printf ("not possible\n");	     
    return;          
}



