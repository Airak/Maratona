#include <bits/stdc++.h>
#define maxn 1020

using namespace std;

int n, m, k;
char s1[maxn], s2[maxn];
int same[maxn][maxn];
int pd[maxn][maxn][2];

int main()
{
	while(1)
	{
		scanf("%d", &k);
		if(!k) break;
		scanf("%s", s1);
		scanf("%s", s2);
		n = strlen(s1);
		m = strlen(s2);
		for(int i = 0; i <= n; ++i)
			same[i][m] = pd[i][m][0] = pd[i][m][1] = 0;
		for(int j = 0; j <= m; ++j)
			same[n][j] = pd[n][j][0] = pd[n][j][1] = 0;
		for(int i = n-1; i >= 0; --i)
			for(int j = m-1; j >= 0; --j)
				if(s1[i] != s2[j]) same[i][j] = 0;
				else same[i][j] = 1+same[i+1][j+1];
			
		
		for(int i = n-1; i >= 0; --i)
			for(int j = m-1; j >= 0; --j)
				for(int block = 0; block < 2; ++block)
				{
					int &p = pd[i][j][block];
					p = max(pd[i+1][j][0], pd[i][j+1][0]);
					p = max(p, pd[i+1][j+1][0]);
					if(block == 0)
					{
						if(same[i][j] >= k)
							p = max(p, pd[i+k][j+k][1]+k);
					}
					else
					{
						if(s1[i] == s2[j])
							p = max(p, pd[i+1][j+1][1]+1);
					}
				}
		
		printf("%d\n", pd[0][0][0]);
	}

	return 0;
}
