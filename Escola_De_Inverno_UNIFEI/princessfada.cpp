#include<bits/stdc++.h>
#define MAXTAM 10005

using namespace std;

long long p[MAXTAM];
long long pd[MAXTAM][2];
int n;

long long func (int i, int levou){
    
    if(i>=n)return 0;
    if(pd[i][levou]>=0) return pd[i][levou];
    
    
    if(levou){
	return pd[i][levou] = func(i+1, false);
    }else if(!levou){
	return pd[i][levou] = max(func(i+1, false), func(i+1, true) + p[i]);	
    }
}

int main(){
    int t,cont=0;
    cin >> t;
    while(t--){
	cin >> n;
	
	for(int i=0; i<n; i++){ 
	    scanf("%lld", &p[i]);
	    pd[i][0]=-1;
	    pd[i][1]=-1;
	}
	
	cout << "Case " << ++cont << ": " << max(func(0, false), func(0, true)) << endl;
    }
    
    return 0;
    
}


