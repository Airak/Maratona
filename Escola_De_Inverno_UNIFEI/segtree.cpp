#include <bits/stdc++.h>

typedef struct node
{
node *pred;
node *left, *right;
int value;
} node;
node *segTree;
node *cacheLeaf[MAX];
int array[MAX], n;
int buildSegTreeRec(node *segment, int l, int r)
{
if(l == r)
{
cacheLeaf[l] = segment;
return segment -> value = array[l];
}
else
{
segment -> left = (node *)malloc(sizeof(node));
segment -> right = (node *)malloc(sizeof(node));
segment ->
segment -> left -> pred = segment;
right -> pred = segment;
segment
segment
segment
segment left -> right = NULL;
left -> left = NULL;
right -> right = NULL;
right -> left = NULL;
->
->
->
->
int left = buildSegTreeRec(segment -> left, l, (l+r)/2);
int right = buildSegTreeRec(segment -> right, (l+r)/2+1, r);
return segment -> value = left*right;
}
}
void buildSegTree()
{
segTree = (node *)malloc(sizeof(node));
