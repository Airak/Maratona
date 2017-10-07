#include <bits/stdc++.h>
#define maxn 2000
using namespace std;

int n;
int pd[maxn][maxn];
vector<int> treat;
/*
    f(i) = 
 */
int f(int i,int j){
    int age = i+n-j;
    if(i==j) return treat[i] * age;
    if(pd[i][j] != -1) return pd[i][j];
    pd[i][j] = max(f(i+1,j) + treat[i]*age, f(i,j-1) + treat[j]*age); 
    pd[j][i] = pd[i][j];
    return pd[i][j]; 
}

int main(){
    cin >> n;
    for(int j=0;j<n;j++){
	int i;
	cin >> i;
	treat.push_back(i);
    }
    memset(pd, -1, sizeof pd);
    cout << f(0,n-1) << endl;
    /*
     1*1 + 2*2 + 3*3 + 4*5 + 5*1 = 1+4+9+20+5 = 14+25 = 39
     */
    return 0;
}