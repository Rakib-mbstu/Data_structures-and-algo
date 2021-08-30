//	            	Bismillah
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define endl "\n"
#define ins insert
#define ps push
#define lim 10000
ll arr[lim];
ll tree[lim*3];
//b->starting of tree,e->ending of tree,node->always from start,(i,j)->relevent section
//zero based indexing....!
void init(int node,int b,int e)
{
	if(b==e)
	{
		tree[node]=arr[b];
		return;
	}
	int left=2*node;
	int right=2*node+1;
	int mid=(b+e)/2;
	init(left,b,mid);
	init(right,mid+1,e);
	tree[node]=tree[left]+tree[right];
}
ll query(int node,int b,int e,int i,int j)
{
	if(b>j or e<i)
		return 0;
	if(b>=i and e<=j)
		return tree[node];
	int left=node*2;
	int right=node*2+1;
	int mid=(b+e)/2;
	return query(left,b,mid,i,j)+query(right,mid+1,e,i,j);
}
void update(int node,int b,int e,int i,int newvalue)
{
	if(b>i or e<i)
		return;
	if(b>=i and e<=i)
	{
		tree[node]=newvalue;
		return;
	}
	int left=node*2;
	int right=node*2+1;
	int mid=(b+e)/2;
	update(left,b,mid,i,newvalue);
	update(right,mid+1,e,i,newvalue);
	tree[node]=tree[left]+tree[right];
}

int main()
{
	int n;
	cin>>n;
	for (int i = 1; i <= n; ++i)
	{
		cin>>arr[i];
	}
	init(1,1,n);
	cout<<query(1,1,n,,2)<<endl;
	return 0;
}