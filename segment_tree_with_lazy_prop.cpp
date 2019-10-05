#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007ll
#define endl "\n"
#define inf (ll)1e8+5;
using namespace std::chrono;

ll n=10;
vector<ll> seg(4*n),lazy(4*n);
void push(ll v)
{
    seg[2*v+1]+=lazy[v];
    lazy[2*v+1]+=lazy[v];
    seg[2*v+2]+=lazy[v];
    lazy[2*v+2]+=lazy[v];
    lazy[v]=0;
}

void build(vector<ll>& ar,ll i,ll start,ll end)
{
    if(start==end)
    {
        seg[i]=ar[start];
        return;
    }
    ll mid=(start+end)/2;
    build(ar,2*i+1,start,mid);
    build(ar,2*i+2,mid+1,end);
    seg[i]=max(seg[2*i+1],seg[2*i+2]);
}

void range_update(ll i,ll start,ll end,ll arstart,ll arend,ll add)
{
    if(arstart>arend)
    {
        return;
    }
    if(start==arstart && end==arend)
    {
        seg[i]+=add;
        lazy[i]+=add;
    }
    else
    {
        push(i);
        ll mid=(start+end)/2;
        range_update(2*i+1,start,mid,arstart,min(arend,mid),add);
        range_update(2*i+2,mid+1,end,max(arstart,mid+1),arend,add);
        seg[i]=max(seg[2*i+1],seg[2*i+2]);
    }
}

ll range_query(ll i,ll start,ll end,ll arstart,ll arend)
{
    if(arstart>arend)
    {
        return -inf;
    }
    if(start>=arstart && end<=arend)
    {
        return seg[i];
    }
    push(i);
    ll mid=(start+end)/2;
    ll ans1=range_query(2*i+1,start,mid,arstart,min(mid,arend));
    ll ans2=range_query(2*i+2,mid+1,end,max(arstart,mid+1),arend);
    return max(ans1,ans2);
}

int main()
{
    n=6;
    vector<ll> ar={1,3,5,7,9,11};
    build(ar,0,0,n-1);
    cout<<range_query(0,0,n-1,2,4)<<endl;
    range_update(0,0,n-1,1,3,5);
    cout<<range_query(0,0,n-1,2,4)<<endl;
    return 0;
}