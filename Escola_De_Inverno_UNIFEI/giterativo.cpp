#include <bits/stdc++.h>
#define maxn 2000
using namespace std;

int n;
int pd[maxn][maxn];
vector<int> treat;

int main(){
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d", &treat[i]);
	for(int i=0;i<n;i++){
		pd[i][i] = n *treat[i];
	}
	for(int tam = 2; tam <=n;++tam){
		for(int i=0;i+tam <=n;++i){
			int j=i+tam-1;
			pd[i][j] = max(pd[i+1][j] + treat[i] 
		}
	}

}
