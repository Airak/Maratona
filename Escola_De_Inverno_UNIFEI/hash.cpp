#include <bits/stdc++.h>
#define eps 1e-8
#define maxn 1000100
using namespace std;
/*ERRADOOOOOOOOOOOOOOOOOOOO*/
typedef long long ll;
typedef unsigned long long ull;
/* usando usigned para dar o primo gigante*/

char s[maxn];
ull h[maxn];
ull h2[maxn];
ull base = 33;
ull pot[maxn];

ull hash(int i, int j){
	return h[j+1] - h[i]*base*pot[j-i+1];
}

ull hash2(int i, int j){
	return h2[i] - h2[j+1]*pot[j-i+1];
}


int main(){
	pot[0]=1;
	for(int i=1;i<maxn;++i)
		pot[i] = pot[i-1]*base;
	int n;
	scanf("%s", s);
	n = strlen(s);	
	h[0] = 0;
	for(int i=1;i<=n;++i){
		h[i] =h[i-1]*base + (s[i-1]-'a'+1);	
	}
	h2[n]=0;
	while(true){
		int x,y;
		cin >> x >> y; //mudar para scanf
		if(hash(x,y) == hash2(x,y))
			printf("eh palindrome\n");
		else
			printf("no eh palindrome\n");
	}
	return 0;
}
