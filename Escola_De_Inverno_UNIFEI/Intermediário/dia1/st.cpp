#include <bits/stdc++.h>

using namespace std;

int r;
int g[111];
int pd[111][111*111/2];

bool f(int v, int k)
{
	if(k == 0) return true;
	if(v == r) return false;
	
	int &p = pd[v][r];
	
	if(p != -1) return p;
	
	p = f(v+1, k);
	if(g[v] <= k)
		p |= f(v+1, k-g[v]);
	
	return p;
}
int main()
{
	int k;
	while(scanf("%d %d", &r, &k) != EOF)
	{
		memset(g, 0, sizeof g);
		for(int i = 0; i < k; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			g[x]++;
			g[y]++;
		}
		memset(pd, -1 ,sizeof pd);
	}
	return 0;
}
