/*
	PDPDPDPDPDPDPDP
	
*/
#include <bits/stdc++.h>
#define maxn 2020


using namespace std;

char a[maxn], b[maxn];
int pd[maxn][maxn];
int n,m;


int f(int i, int j){
	if(i == n) return m-j;
	if(j == m) return n-i;
	
	int &p = pd[i][j];
	if(p != -1) return p;
	p = f(i+1, j+1)+1;
	p = min(p, f(i,j+1)+1);
	p = min(p, f(i+1,j)+1);

	if(a[i] == b[j])
		p = min(p, f(i+1, j+1));
	return p;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%s", a);
		scanf("%s", b);
		n = strlen(a);
		m = strlen(b);
		memset(pd,-1,sizeof pd);
		printf("%d\n", f(0,0));
	}
	return 0;
}
