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
  int c,l;
  int t=0;
  while(scanf("%d %d", &c,&l) && (c+l)){
      //visitado.assign(c+1, 0);
      
      for(int i=0;i<c; i++)
	MakeSet(i);
      
      
      for(int i=0; i<l; i++){
	  int x, y;
	  scanf("%d %d", &x, &y);
	  x--;y--;
	  Union(x,y);
      }
      
      bool ok = true;      
      int aux=find(0);
      
      for(int i=1; i<c; i++){
	    if(find(i)!=aux){
		ok=false;
		break;
	    }
    }
    
      cout << "Teste " << ++t << endl;
       if(ok)
	  cout << "normal" << endl;
      else
	  cout << "falha" << endl;
      cout << endl;
	  
    }
    
  return 0;
}
