#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 10000000

using namespace std;

int t, N,C,p,q,v;

typedef struct node
{
	node *pred;
	node *left, *right;
	int value;
} node;
node *segTree;
node *cacheLeaf[MAX];
int vet[MAX], n;
int buildSegTreeRec(node *segment, int l, int r)
{
	if(l == r)
	{
		cacheLeaf[l] = segment;
		segment -> value = vet[l];
		return segment ->value ;
		
	}
	else
	{
		segment -> left = (node *)malloc(sizeof(node));
		segment -> right = (node *)malloc(sizeof(node));
		segment -> right -> pred = segment;
		segment -> left -> pred = segment;
		segment -> left -> left = NULL;
		
		segment -> right -> right = NULL;
		segment->right -> left = NULL;
		
		segment -> left -> right = NULL;
		int left = buildSegTreeRec(segment -> left, l, (l+r)/2);
		int right = buildSegTreeRec(segment -> right, (l+r)/2+1, r);
		return segment -> value = left+right;
	}
}
void buildSegTree()
{

	segTree = (node *)malloc(sizeof(node));
	segTree -> pred = NULL;
	segTree -> left = NULL;
	segTree -> right = NULL;
	buildSegTreeRec(segTree, 0, n-1);
}
int queryRec(node *segment, int &l, int &r, int i, int j)
{
	if((i == j) || (i >= l && i <= r && j >= l && j <= r))
	{
		return segment -> value;
	}
	else
	{
		int a = (i+j)/2;
		int b = a+1;
		int p1, p2;
		p1 = p2 = INF;
		if((i >= l && i <= r) || ((a >= l) && (a <= r)) || ((i < l) && (a > r))) p1 = queryRec(segment -> left, l, r, i, a);
		if(((b >= l) && (b <= r)) || ((j >= l) && (j <= r)) || ((b < l) && (j > r))) p2 = queryRec(segment -> right, l, r, b, j);
		if(p1 == INF && p2 == INF) return 1;
		else if(p1 == INF) return p2;
		else if(p2 == INF) return p1;
		else return p1+p2;
	}
}
inline int query(int l, int r)
{
	return queryRec(segTree, l, r, 0, n-1);
}
void update(int p, int val)
{
	int left, right;
	node *segment = cacheLeaf[p];
//	int den = segment -> value;
	segment -> value = val;
	segment = segment -> pred;
	while(segment)
	{
		left = right = 1;
		if(segment -> left) left = segment -> left -> value;
		if(segment -> right) right = segment -> right -> value;
		segment -> value = left+right;
		segment = segment -> pred;
	}
	vet[p] += val;
}

int main(){
	cin >> t;
	int i,j,s;
	while(t--){
		cin >> n >> C;
		memset(vet,0,sizeof(vet));
		buildSegTree();
		while(C--){
			cin >> p;
			if(p==0){
				cin >> i >> j >> s;
				for(int ini=i-1;ini<j;ini++){
					update(ini,s);
				}
			}	
			else{
				cin >> i >> j;	
				//cout << i << ' ' << j << endl;
				int soma=0;
				for(int ini=i-1;ini<j;ini++){
					soma += vet[ini];
				}
				//cout << endl;
				//cout << query(--i,--j) << endl;
				cout << soma << endl;			
			}
		
		}
	}
	return 0;
}
