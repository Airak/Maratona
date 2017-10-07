#include <bits/stdc++.h>
#define inf 0x3F3F3F3F
#define mp make_pair

using namespace std;

int n, m, k;
char s[111][111];
int id[111][111];
int x[111], y[111];
int dist[20][20];
int vis[111][111];

int di[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dj[] = {1, -1, 2, 2, 1, -1, -2, -2};

void bfs(int ini)
{
	memset(dist[ini], inf, sizeof dist[ini]);
	dist[ini][ini] = 0;
	memset(vis, inf, sizeof vis);
	vis[x[ini]][y[ini]] = 0;
	queue<pair<int, int> > q;
	q.push(mp(x[ini], y[ini]));
	while(!q.empty())
	{
		int i = q.front().first, j = q.front().second;
		q.pop();
		for(int k = 0; k < 8; ++k)
		{
			int ii = i+di[k], jj = j+dj[k];
			if(ii < 0 || jj < 0 || ii >= n || jj >= m) continue;
			if(s[ii][jj] == '#') continue;
			if(vis[ii][jj] != inf) continue;
			vis[ii][jj] = vis[i][j]+1;
			q.push(mp(ii, jj));
			if(id[ii][jj] != -1)
			{
				dist[ini][ id[ii][jj] ] = vis[ii][jj];
			}
		}
	}
}
int pd[1<<15][16];

int f(int mask, int pos)
{
	if(mask == (1<<k)-1) return dist[pos][k];
	int &p = pd[mask][pos];
	if(p != -1) return p;
	p = inf;
	for(int i = 0; i < k; ++i)
	{
		if(mask&(1<<i)) continue;
		p = min(p, f(mask|(1<<i), i)+dist[pos][i]);
	}
	return p;
}

int main()
{
	while(1)
	{
		int cnt = 0;
		scanf("%d %d %d", &n, &m, &k);
		memset(id, -1, sizeof id);
		for(int i = 0; i < n; ++i)
		{
			scanf("%s", s[i]);
			for(int j = 0; j < m; ++j)
			{
				if(s[i][j] == 'P')
				{
					x[cnt] = i;
					y[cnt] = j;
					id[i][j] = cnt++;					
				}
				if(s[i][j] == 'C')
				{
					x[k] = i;
					y[k] = j;
					id[i][j] = k;
				}
			}
		}
		for(int i = 0; i <= k; ++i)
			bfs(i);
		memset(pd, -1, sizeof pd);
		printf("%d\n", f(0, k));
	}
}
