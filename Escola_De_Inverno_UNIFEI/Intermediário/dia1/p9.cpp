#include <bits/stdc++.h>

using namespace std;

const int N = 20;

long long g[N][N];
//g[i][j] = custo de satisfação i, j
int n, m, k;
long long c[N];
//Satisfação i-ésimo prato

long long pd[(1 << N)][N];

long long func(int mask, int ult) {
	if(__builtin_popcount(mask) == m) return 0;
	if(pd[mask][ult] != -1) return pd[mask][ult];
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		if((mask >> i) & 1) continue;
		ans = max(ans,  c[i] + g[ult][i] + func(mask | (1 << i), i));
	}
	return pd[mask][ult] = ans;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; ++i) scanf("%lld", c + i);
	for(int i = 0; i < k; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		g[a][b] = c;
	}
	memset(pd, -1, sizeof pd);
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		ans = max(ans, c[i] + func(1 << i, i));
	}
	printf("%lld\n", ans);
	return 0;
}
