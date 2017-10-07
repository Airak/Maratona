#include <bits/stdc++.h>
#define maxn 100020

using namespace std;

typedef long long ll;
ll st[4*maxn], lz[4*maxn];

void prop(int no, int l, int r, int mid)
{
	st[no*2] += lz[no]*(mid-l+1);
	st[no*2+1] += lz[no]*(r-(mid+1)+1);
	lz[no*2] += lz[no];
	lz[no*2+1] += lz[no];
	lz[no] = 0;
}

void update(int no, int l, int r, int ini, int fim, ll valor)
{
	if(l > fim || r < ini) return;
	if(l >= ini && r <= fim)
	{
		st[no] += (r-l+1)*valor;
		lz[no] += valor;
		return;
	}
	int mid = (l+r)/2;
	prop(no, l, r, mid);
	update(no*2, l, mid, ini, fim, valor);
	update(no*2+1, mid+1, r, ini, fim, valor);
	st[no] = st[no*2] + st[no*2+1];
}

ll query(int no, int l, int r, int ini, int fim)
{
	if(l > fim || r < ini) return 0;
	if(l >= ini && r <= fim) return st[no];
	int mid = (l+r)/2;
	prop(no, l, r, mid);
	ll p1 = query(no*2, l, mid, ini, fim);
	ll p2 = query(no*2+1, mid+1, r, ini, fim);
	return p1+p2;
}

int main()
{
	int n, x, y, valor, t, op, q;
	scanf("%d", &t);
	while(t--)
	{
		memset(st, 0, sizeof st);
		memset(lz, 0, sizeof lz);
		scanf("%d %d", &n, &q);
		for(int i = 0; i < q; ++i)
		{
			scanf("%d", &op);
			if(!op)
			{
				scanf("%d %d %d", &x, &y, &valor);
				x--; y--;
				update(1, 0, n-1, x, y, valor);
			}
			else
			{
				scanf("%d %d", &x, &y);
				x--, y--;
				printf("%lld\n", query(1, 0, n-1, x, y));
			}
		}
	}
	
	return 0;
}
