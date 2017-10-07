#include<bits/stdc++.h>
#define maxn 200050

using namespace std;

struct e{
	int a, b, p;
};

e E[maxn];


int pai[maxn];

int find(int n){
	while(pai[n]!=n)
		n=pai[n];
	return n;		
}

void uni(int i, int j){
	int a, b;
	a = find(i);
	b = find(j);
	
	if(a==b) return;
	
	pai[b]=a;
}

bool cmp(e a, e b){
	return a.p < b.p;
}

int kk(int m){
 	int t=0;
 	sort(E, E+m, cmp);

	for(int i=0; i<m; i++){
		if(find(E[i].a) != find(E[i].b )){
			t+=E[i].p;	
			uni(E[i].a, E[i].b);
		}
	}
	return t;
}

int main(){
	int n, m, i;
	
	while(scanf(" %d %d", &n, &m) && (n+m)){
	  int aux=0;

	for(i=0; i<m; i++){
		scanf("%d %d %d", &E[i].a, &E[i].b, &E[i].p);
		aux+=E[i].p;
	}
	
	for(i=0; i<n; i++)
		pai[i]=i;
	
	printf("%d\n", aux-kk(m));	
	
	}
	return 0;
}
