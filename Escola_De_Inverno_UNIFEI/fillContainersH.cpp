#include <bits/stdc++.h>
#define 0x3F3F3F3F3F
#define mp make_pair
using namespace std;

int main(){
	int n,m;
	while(scanf("%d %d", &n,&m) != EOF){
		int low = 0;		
		for(int i=0;i<n;++i){
			scanf("%d", &v[i]);
			low = max(low,v[i]);
			high += v[i];
		}
		low--;
		while( lo < hi-1){
			int mid = (low+high)/2;
			if(test(mid) == false){
				low = mid;
			}
			else{
							
			}
		}	
	}
}
