#include <bits/stdc++.h>
#define maxn 100000
using namespace std;

int pai[maxn];
int tam[maxn];

void MakeSet(int n){
 
        tam[n]=1;
        pai[n]=n;
 
}
 
int find(int n){
 
        if(pai[n]==n)
                return n;
               
        int temp = find(pai[n]);
        pai[n]=temp;
        return temp;
 
}
 
void Union(int a, int b){
 
 
        if(find(a)==find(b))
                return;
               
        if(tam[a]<tam[b]){
                pai[find(a)]=find(b);
                tam[b]+=tam[a];
        }
        else{
                pai[find(b)]=find(a);
                tam[a]+=tam[b];
        }
 
        return;

}

int main(){
  int n,m;
  while(scanf("%d %d", &n, &m) && (n+m)){
    vector <int> pontos;
        
    int vic=0;
    for(int i=0;i<n; i++)
      MakeSet(i);
    
    while(n--){
      int i;
      cin >> i;
      pontos.push_back(i);
    }
    
    while(m--){
      int op,j1,j2;
      cin >> op >> j1 >> j2;
      j1--;
      j2--;
      if(op == 1){
	int aux = pontos[find(j1)];
	pontos[find(j1)]+=pontos[find(j2)];
	pontos[find(j2)]+=aux;
	Union(j1,j2);
      }
      else{
	    int pR = find(0);
	    
	    if(pR == find(j1) && pontos[find(j1)]>pontos[find(j2)])
		vic++;
	    else if (pR == find(j2) && pontos[find(j1)]<pontos[find(j2)])
		vic++;	
      }
      
    }
    cout << vic << endl;
    
  }
  return 0;
}