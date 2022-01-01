//	            	 Bismillah
#include "bits/stdc++.h"
using namespace std;
#define ll long long 
#define pb push_back
#define endl "\n"
#define ins insert
#define ps push
#define pp pair
#define fast  ios_base::sync_with_stdio(false); cin.tie(NULL);
/*
the seg tree is one base indexed.




*/
ll mod=1e9+7;
ll mxl=1e5+7;
vector<ll> tree(4*100000);
void build(vector<ll> &v,ll index,ll start,ll end)
{
	if(start>end)
		return;
	if(start==end)
	{
		tree[index] = v[start];
		return;
	}
	//bottom up segment build(Spread and build).
	ll mid = (start+end)/2;
	build(v,2*index,start,mid);
	build(v,2*index+1,mid+1,end);
	tree[index] = tree[2*index] + tree[2*index+1];
}
void update(ll index,ll start,ll end,ll idx,ll val)
{
	if(start>idx || end<idx)
		return;
	if(idx<=start and idx>=end)
	{
		tree[index] += val;
		return;
	}
	//update recursively..
	ll mid = (start+end)/2;
	update(2*index,start,mid,idx,val);
	update(2*index+1,mid+1,end,idx,val);
	tree[index] = tree[index*2]+tree[1+2*index]; 
}
//range sum/mul i to j
ll query(ll index,ll start,ll end,ll i,ll j)
{
	if(start>j or end<i)
		return 0;
	if(start>=i and j>=end)
		return tree[index];
	ll mid  = (start+end)/2;
	ll q1 = query(index*2,start,mid,i,j);
	ll q2 = query(index*2+1,mid+1,end,i,j);
	return q1+q2;
}
signed main()
{
	build(v,1,0,n-1);//values of n element is in v.
	update(1,0,n-1,idx,val);//idx means index that is supposed to update with the value val.
	query(1,0,n-1,t,y)//query starting from t to y inclusively.
	return 0;
}
