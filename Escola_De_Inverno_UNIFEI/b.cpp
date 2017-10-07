#include <bits/stdc++.h>

using namespace std;

#define NAO_VISITADO 0
#define VISITADO 1
#define INFINITO 9999999

vector < vector<int> > ladj;
vector < vector<int> > custo;
vector <int> visitado;
vector <int> dist;


int s, o,q;
int x, y, w;
int cont;
int n;
void Dijkstra(int S);
void desce (int p, int n);
void sobe (int f);



int main(){
	map <string,int> mapa;

	int na;
	cin >> n >> na;		
	ladj.resize(n);
	custo.resize(n);
	dist.resize(n);
	int i=0;
	while(na--){	
		
		string x,y;
		cin >> x >> y;
		if(x == "Entrada"){
			if(mapa.find(y) != mapa.end()){
				s = mapa[y];
			}
			else{
				s = ++i;
				mapa[y]=i;				
			}	
			ladj[mapa[y]].push_back(mapa[x]);
			custo[mapa[y]].push_back(1);

		}
		else if(y == "Saida"){
			if(mapa.find(x) != mapa.end()){
				o = mapa[x];
			}			
			else{
				o = ++i;
				mapa[x]=i;
			}				
			ladj[mapa[x]].push_back(mapa[y]);
			custo[mapa[x]].push_back(1);	

		}
		else if(y == "Entrada"){
			if(mapa.find(x) != mapa.end()){
				s = mapa[x];
			}
			else{
				s = ++i;
				mapa[x]=i;				
			}	
			ladj[mapa[x]].push_back(mapa[y]);
			custo[mapa[x]].push_back(1);

		}
		else if(x == "Saida"){
			if(mapa.find(y) != mapa.end()){
				o = mapa[y];
			}			
			else{
				o = ++i;
				mapa[y]=i;
			}				
			ladj[mapa[y]].push_back(mapa[x]);
			custo[mapa[y]].push_back(1);	

		}
		
		else{
			
			if(mapa.find(x) != mapa.end());
			else
				mapa[x] = ++i;
			if(mapa.find(y) != mapa.end());
			else			
				mapa[y] = ++i;

			if(x=="*") q = mapa[x];
			else if(y=="*")	q = mapa[y];
			
			ladj[mapa[x]].push_back(mapa[y]);
			custo[mapa[x]].push_back(1);	
			ladj[mapa[y]].push_back(mapa[x]);
			custo[mapa[y]].push_back(1);
		}	
	}
	Dijkstra(s);
	int aux = dist[q];	
	Dijkstra(q);
	aux += dist[o];
	cout << aux+2 << endl;
	
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

		for(unsigned int i=0; i < ladj[posMenor].size(); i++){
			
			vz = ladj[posMenor][i];
			if(dist[posMenor] + custo[posMenor][i]  <  dist[vz])
				dist[vz] = dist[posMenor] + custo[posMenor][i];
		}
	
	}
	
	visitado.clear();

}


