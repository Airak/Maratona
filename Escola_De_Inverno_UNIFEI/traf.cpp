#include <bits/stdc++.h>

using namespace std;

#define MAX 101
#define NAO_VISITADO 0
#define VISITADO 1

vector<int> ladj[MAX];
vector<int> visitado;

int cont;
void busca_profundidade(int);

int main(){
  int c,l;
  int t=0;
  while(scanf("%d %d", &c,&l) && (c+l)){
      visitado.assign(c+1, 0);
      
      for(int i=0; i<l; i++){
		  int x, y;
		  scanf("%d %d", &x, &y);
		  x--;y--;
		  ladj[x].push_back(y);
		  ladj[y].push_back(x);
      }
      int aux=0;
      bool ok = true;

	  cont=0;
      busca_profundidade(0);
	    
	  if(cont != c) ok = false;

      cout << "Teste " << ++t << endl;

      if(ok) cout << "normal" << endl;
      else cout << "falha" << endl;
		
	  for (int i=0; i<c; i++) ladj[i].clear();
      cout << endl;
	  
    }  
  return 0;
}

void busca_profundidade (int vertice){

	visitado[vertice]=VISITADO; 
	++cont;
	
	for(vector<int>::iterator it = ladj[vertice].begin(); it != ladj[vertice].end(); ++it) {
        	
	    int v = *it;
	    
		if(visitado[v] == NAO_VISITADO){
			// Ou seja, se o vértice determinado ainda não foi visitado
			busca_profundidade(v);
		}
	} 
    	
	if(find(tasks.begin(), tasks.end(), vertice) == tasks.end()){
	    tasks.push_front(vertice);
	}
}

