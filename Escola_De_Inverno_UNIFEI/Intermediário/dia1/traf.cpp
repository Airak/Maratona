#include <bits/stdc++.h>
#define inf 0x3F3F3F3F
#define maxn 10010

using namespace std;

int n, m, k, s, t;
int dist[maxn][2];

struct edge
{
	int y, c, esp;
	edge(){}
	edge(int y, int c, int esp):y(y),c(c),esp(esp){}
};

vector<edge> g[maxn];

struct no
{
	int x, d, esp;
	no(){}
	no(int x, int d, int esp):x(x),d(d),esp(esp){}
	
	bool operator < (no other) const
	{
		if(d < other.d) return true;
		else return false;
	}
};

void dijkstra()
{
	dist[s][0] = 0;
	priority_queue<no> fila;
	fila.push(no(s, 0, 0));
	while(!fila.empty())
	{
		int x = fila.top().x;
		int d = -fila.top().d;
		int esp = fila.top().esp;
		fila.pop();
		if(d > dist[x][esp]) continue;
		for(int i = 0; i < g[x].size(); ++i)
		{
			int y = g[x][i].y;
			int c = g[x][i].c;
			int tipo = g[x][i].esp;
			if(esp == 1 && tipo == 1) continue;
			
			int novoEsp = tipo | esp;
			
			if(dist[y][novoEsp] > dist[x][esp] + c)
			{
				dist[y][novoEsp] = dist[x][esp] + c;
				fila.push(no(y, -dist[y][novoEsp], novoEsp));
			}
		}
	}	
}

int main()
{
	int test;
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);
		for(int i = 1; i <= n; ++i)
		{
			g[i].clear();
			dist[i][0] = dist[i][1] = inf;
		}
		for(int i = 0; i < m; ++i)
		{
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c);
			edge aresta;
			aresta.y = y;
			aresta.c = c;
			aresta.esp = 0;
			g[x].push_back(edge(y, c, 0));
		}
		for(int i = 0; i < k; ++i)
		{
			int x, y, c;
			scanf("%d %d %d", &x, &y, &c);
			g[x].push_back(edge(y, c, 1));
			g[y].push_back(edge(x, c, 1));
		}
		dijkstra();
		int resp = min(dist[t][0], dist[t][1]);
		if(resp == inf) printf("-1\n");
		else printf("%d\n", resp);
	}
}
