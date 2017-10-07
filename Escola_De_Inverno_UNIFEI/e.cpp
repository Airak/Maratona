#include <bits/stdc++.h>
#define maxn 1000000
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
  int t,n,cont=0;
  string s;
  scanf("%d ", &t);
  getline(cin,s);
  while(t--){
	if(s == "") getline(cin,s);
	if(cont)
		cout << endl;
	int ok=0, nok=0;
	n  = atoi(s.c_str());
	for(int i=1;i<=n; i++)
           MakeSet(i);    	
	while(getline(cin,s) && (s[0]=='q' || s[0]=='c')){
		int x,y,i;
		string s1="";
		for(i=2;i<s.size();i++){
			if(s[i] ==  ' '){i++; break;}
			s1 += s[i];
		}
		x = atoi(s1.c_str());
		s1 = "";
		for(i;i < s.size();i++) s1+=s[i];
		cout << s1 << endl;		
		y = atoi(s1.c_str());
			
		if(s[0]=='c'){			
			Union(x,y);		
		}
		else{
			if(find(x) == find(y)) ok++;
			else nok++;	
		}
    	}
	cont++;
	cout << ok << "," << nok << endl;  	
    
    }
    
  return 0;
}
