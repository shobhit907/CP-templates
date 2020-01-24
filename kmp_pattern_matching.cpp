#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007ll
#define mod1 998244353ll
#define endl "\n"
#define inf (ll)1e18+1
using namespace std::chrono;

vector<ll> build_lps(string &pat){
    ll sz=pat.size();
    vector<ll> lps(sz);
    lps[0]=0;
    ll j=0,i=1;
    while(i<sz){
        if(pat[i]==pat[j]){
            lps[i]=j+1;
            i++;
            j++;
        }else{
            if(j==0){
                i++;
            }else{
                j=lps[j-1];
            }
        }
    }
    return lps;
}

vector<ll> kmp_search(string &s,string &pat,vector<ll>& lps){
    vector<ll> index;
    ll j=0,i=0;
    ll n=s.length();
    ll m=pat.length();
    while(i<n){
        if(s[i]==pat[j]){
            i++;
            j++;
            if(j==m){
                index.push_back(i-m);
                j=lps[j-1];
            }
        }else{
            if(j==0){
                i++;
            }else{
                j=lps[j-1];
            }
        }
    }
    return index;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string pat,s;
    cin>>s>>pat;
    vector<ll> lps=build_lps(pat);  //lps[i]=Longest proper prefix of the string s[0..i] which is also a suffix
    // for(ll x:lps){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    vector<ll> index=kmp_search(s,pat,lps);
    // for(ll x:index){
    //     cout<<x<<" ";
    // }
    // cout<<endl;
    cout<<index.size()<<endl;
    return 0;
}