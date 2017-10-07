#include <bits/stdc++.h>

using namespace std;

vector<int> g[2020];
int n, m;
int vis[2020];

void dfs(int x)
{
	vis[x] = 1;
	for(int i = 0; i < g[x].size(); ++i)
	{
		int y = g[x][i];
		if(vis[y]) continue;
		dfs(y);
	}
}

int main()
{
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(!n && !m) break;
		for(int i = 1; i <= n; ++i)
		{
			g[i].clear();
		}
		for(int i = 0; i < m; ++i)
		{
			int x, y, p;
			scanf("%d %d %d", &x, &y, &p);
			g[x].push_back(y);
			if(p == 2)
				g[y].push_back(x);
		}
		
		int ok = 1;
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
				vis[j] = 0;
			dfs(i);
			for(int j = 1; j <= n; ++j)
				if(!vis[j])
					ok = 0;
		}
		printf("%d\n", ok);
	}	
	return 0;
}
