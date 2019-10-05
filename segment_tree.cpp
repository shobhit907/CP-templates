#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007ll
#define endl "\n"
#define inf (ll)1e8+5;
using namespace std::chrono;

ll n=10;
vector<ll> seg(4*n);
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

ll range_query(ll i,ll start,ll end,ll arstart,ll arend)
{
    if(arstart>arend)
    {
        return -inf;
    }
    if(arstart==start && arend==end)
    {
        return seg[i];
    }
    ll mid=(start+end)/2;
    ll ans1=range_query(2*i+1,start,mid,arstart,min(mid,arend));
    ll ans2=range_query(2*i+2,mid+1,end,max(arstart,mid+1),arend);
    return max(ans1,ans2);
}

void update_query(ll i,ll start,ll end,ll ari,ll val)
{
    if(start==end)
    {
        seg[i]=val;
        return;
    }
    ll mid=(start+end)/2;
    if(ari<=mid)
    {
        update_query(2*i+1,start,mid,ari,val);
    }
    else
    {
        update_query(2*i+2,mid+1,start,ari,val);
    }
    seg[i]=max(seg[2*i+1],seg[2*i+2]);
}

int main()
{
    n=5;
    vector<ll> ar={1,3,-2,8,-7};
    build(ar,0,0,n-1);
    update_query(0,0,n-1,2,4);
    cout<<range_query(0,0,n-1,0,n-1)<<endl;
    cout<<range_query(0,0,n-1,0,2)<<endl;
    cout<<range_query(0,0,n-1,3,4)<<endl;
    cout<<range_query(0,0,n-1,0,1)<<endl;
    cout<<range_query(0,0,n-1,2,2)<<endl;
    cout<<range_query(0,0,n-1,3,3)<<endl;
    cout<<range_query(0,0,n-1,4,4)<<endl;
    cout<<range_query(0,0,n-1,0,0)<<endl;
    cout<<range_query(0,0,n-1,0,1)<<endl;
    return 0;
}