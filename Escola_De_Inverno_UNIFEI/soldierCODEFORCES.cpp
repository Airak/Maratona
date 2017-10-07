#include <bits/stdc++.h>
#define maxn 5000020

using namespace std;

ll fat[maxn];
vector <int> primos;

void crivo(){
	if(fat[i] != 0) continue;

	for(int i=2;i<=maxn;++i){
		if(fat[i] != 0) continue;
	
		fat[i] = 1;		
		primos.push_back(i);

		for(int j=i+1; j<maxn; j+= i){
			int aux = j;
			while(aux%i == 0){
				fat[j]++;	
				aux /= i;
			}
		}
	}
}

void crivofat(){
	for(int i=2;i<=maxn;++i){
	
		if(fat[i] != 0) continue;
	
		fat[i] = i;
		for(int j=i+i; j<maxn; j+= i){
			int aux = j;
			if(fat[j] == 0)
				fat[j] = i ;
		}
	}
}

int main(){
	crivo();
	return 0;
}
