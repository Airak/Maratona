#include <bits/stdc++.h>
#define maxn 100020

using namespace std;

long long st[4*maxn], lz[4*maxn];
long long v[maxn];

void prop(int no, int l, int r, int mid){
	st[no*2] += lz[no]*(mid-l+1);
	st[no*2+1] += lz[no]*(r-(mid+1)+1);
	lz[no*2] += lz[no];
	lz[no*2+1] += lz[no];
	lz[no] = 0;	
}

void update(int no, int l, int r, int ini, int fim, long long valor){
	if(l > fim || r < ini) return;
	if(l >= ini && r<=fim){
		st[no] += (r-l+1)*valor;
		lz[no] += valor;
		return;
	}
	int mid = (l+r)/2;
	prop(no, l, r,mid);
	update(no*2, l, mid, ini, fim, valor);
	update(no*2+1, mid+1, r, ini, fim, valor);
	st[no] = st[no*2] + st[no*2+1];
}

long long query(int no, int l, int r, int ini, int fim){
	if(l > fim || r < ini) return 0;
	if(l >= ini && r<=fim) return st[no];
	int mid = (l+r)/2;
	prop(no,l,r,mid);
	//long long int p1 = query(no*2,l,mid,ini,fim);
	//long long int p2 = query(no*2+1,mid+1,r,ini,fim);
	return query(no*2,l,mid,ini,fim) + query(no*2+1,mid+1,r,ini,fim);
}

int main(){
	int n,t,c, p;
	long long  valor;
	int x, y;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &c);
		memset(lz,0,sizeof lz);
		memset(st,0,sizeof st);
		while(c--){
			cin >> p;
			if(p==0){
				scanf("%d %d %lld", &x, &y, &valor);
				update(1,0,n-1,x-1,y-1,valor);
			}
			else{
				scanf("%d %d", &x, &y);
				printf("%lld\n", query(1,0,n-1,x-1,y-1));	
			}
		}
		
		
	}	
	return 0;
}

/*
	
*/
