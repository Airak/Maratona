#include <bits/stdc++.h>
#define eps 1e-8
#define maxn 110
#define inf 3x03F3F3F
using namespace std;

typedef long long ll;
/*
	FLUXO MAXIMO COM CUSTO MINIMO. TALVEZ
	distancia * fluxo maximo
	PROBLEMA DA MINIMA LATENCIA;
	FAZER ISSO NA INICIAÇÃO CIENTIFCA =)
*/
int s,t;
int vis[maxn];
int flow[maxn][maxn]; //matriz que guardara o fluxo entre dois vertices
vector<int> g[maxn];
int pai[maxn]; // vetor de antecessores (pai no bfs)

ll a

bool bfs(){
	queue<int>fila;
	fila.push(s);
	memset(pai,-1,sizeof pai);
	pai[s] = -2;
	while(!fila.empty()){
		
		int x = fila.front(); fila.pop();
		
		for(int i=0;i<g[x].size();i++){

			int y = g[x][i];
		
			if(pai[y]==-1 && && flow[x][y]){
				pai[y]=x;
				fila.push(y);
				if(y == t ) return true;			
			}
		}
	}
	return false;
}

int maxflow(){
	int total = 0;
	while(bfs()){
		int f =INF;
		int x = t;

		while(x!=s){
			f = min(f,flow[pai[x]][x]);
			x = pai[x];		
		}

		x=t;

		while(x != s){
			flow[pai[x]][x] -= f;
			flow[x][pai[x]] += f;
			x = pai[x];
		}

		total += f;	
	}
	return total;
}

int main(){
	int n,m;
	while(true){
		scanf("%d", &n);
		if(!n) break;
		scanf("%d %d %d", &s, &t, &m);
		for(int i=1;i<=n;++i){
			g[i].clear();
			for(int j=1;j<=n;++j){
				flow[i][j]=0;
			}	
		}
		for(int i=0;i<m;++i){
			int x,y,,c;
			scanf("%d %d %d\n", &x,&y,&m);
		}
	}
	
	return 0;
}
