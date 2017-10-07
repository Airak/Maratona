#include <bits/stdc++.h>
#define maxn 1000100
#define eps 13-8


typedef long long ll;

using namespace std;

int v[maxn];
int ft[maxn];


int last(int x){
	return (x&(-x));	
}

int query(int pos){
	for(;pos>0;pos-=last(pos))
		soma +== ft[pos];
	return soma;

}

void update(int pos, int valor){
	for(;pos < maxn;pos += last(pos))
		ft[pos] += valor;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;++i){
		scanf("%d", &v[i]);
		update(i,v[i]);
	}
	return 0;
}


/*
	8 - 1000
	2^3
	6 = 110  -> 2^1 = 2. 
  	    012	
	5 = 


	8 --------
	4 ----
	2 --
	1 -3-


*/

