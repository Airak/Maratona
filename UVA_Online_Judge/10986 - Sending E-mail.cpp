#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define NAO_VISITADO 0
#define VISITADO 1
#define INFINITO 9999999

vector < vector<int> > ladj;
vector < vector<int> > custo;
vector <int> visitado;
vector <int> dist;


int N, n, m, s, t;
int x, y, w;
int cont;

void Dijkstra(int S);
void desce (int p, int n);
void sobe (int f);

int main(){

	cont=0;
	scanf("%d", &N);
	
	while(N--){

		scanf("%d %d %d %d", &n, &m, &s, &t);
			
			
		dist.clear();
		for (int i = 0; i< ladj.size(); i++)
			ladj[i].clear();	
		ladj.clear();
		for (int i = 0; i< custo.size(); i++)
			custo[i].clear();	
		custo.clear();
		
		ladj.resize(n);
		custo.resize(n);
		dist.resize(n);
		
		while(m--){

			scanf("%d %d %d", &x, &y, &w);	
			ladj[x].push_back(y);
			ladj[y].push_back(x);
			custo[y].push_back(w);
			custo[x].push_back(w);

		}
		
		cont++;
		Dijkstra(s);
		
		if(dist[t]!=INFINITO)
			printf("Case #%d: %d\n", cont,dist[t]);	
		else	
			printf("Case #%d: unreachable\n", cont);
		
	}
	return 0;

}



void Dijkstra(int S){

	int vz;
	visitado.resize(n);
	
	for(int i=0; i<n; i++){
		dist[i]=INFINITO;
		visitado[i]=NAO_VISITADO;
	}

	dist[S]=0;
	
	int aux=n;
	while(aux--){
	
		int menor = INFINITO;
		int posMenor = -1;
	

		for(int i=0; i<n; i++)
			if(visitado[i]==NAO_VISITADO && dist[i]<menor){
				menor=dist[i];
				posMenor=i;
			}
			
		if (posMenor == -1)
			break;
		visitado[posMenor]=VISITADO;

		for(int i=0; i < ladj[posMenor].size(); i++){
			
			vz = ladj[posMenor][i];
			if(dist[posMenor] + custo[posMenor][i]  <  dist[vz])
				dist[vz] = dist[posMenor] + custo[posMenor][i];
		}
	
	}
	
	visitado.clear();

}

