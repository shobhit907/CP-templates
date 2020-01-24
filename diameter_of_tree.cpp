#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007ll
#define mod1 998244353ll
#define endl "\n"
#define inf (ll)1e18+1
using namespace std::chrono;

pair<ll,ll> dfs(vector<ll> edges[],ll u,ll p,vector<ll>& parent){
    pair<ll,ll> pa={u,0};
    parent[u]=p;
    for(ll v:edges[u]){
        if(v!=p){
            pair<ll,ll> child=dfs(edges,v,u,parent);
            ll dis1=child.second+1;
            if(dis1>pa.second){
                pa={child.first,dis1};
            }
        }
    }
    return pa;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll> edges[n];
    for(ll x=0;x<n-1;x++){
        ll u,v;
        cin>>u>>v;
        u--;
        v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<ll> parent(n);
    pair<ll,ll> pa1=dfs(edges,0,0,parent);
    pair<ll,ll> pa2=dfs(edges,pa1.first,pa1.first,parent);
    /*
    pa2.first & pa1.first are end points of diameter. They will always be the leaves of tree.
    pa2.second is the length of diameter counted as the no. of edges between the two end points of the diameter
    */
    return 0;
}