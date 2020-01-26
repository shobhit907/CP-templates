#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod1 998244353ll
#define endl "\n"
#define inf (ll)1e18+1
using namespace std::chrono;

const ll mod=1000000007ll;
const ll mod2=mod-1;

class Matrix{
    public:
    vector<vector<ll>> mat;
    int rows,cols;
    Matrix(ll rows,ll cols){
        this->rows=rows;
        this->cols=cols;
        mat.resize(rows,vector<ll>(cols));
    }
    Matrix(vector<vector<ll>> ar){
        mat=ar;
        this->rows=ar.size();    
        this->cols=ar[0].size();
    }
    static Matrix identity_matrix(ll n){
        vector<vector<ll>> values(n,vector<ll>(n,0));
        for(ll x=0;x<n;x++){
            values[x][x]=1;
        }
        return move(Matrix(move(values)));
    }
    Matrix multiply(Matrix &other,ll do_mod){
        ll n = rows, m = other.cols;
        vector< vector<ll> > result(n, vector<ll>(m, 0));
        for(ll i = 0; i < n; i++)
            for(ll j = 0; j < m; j++) {
                ll tmp = 0;
                for(int k = 0; k < cols; k++) {
                    tmp += mat[i][k] * other.mat[k][j];
                    tmp%=do_mod;
                }
                tmp+=do_mod;
                result[i][j] = tmp % do_mod;
            }

        return move(Matrix(move(result)));
    }
    Matrix power(ll n,ll do_mod){
        Matrix result=identity_matrix(rows);
        Matrix temp=Matrix(mat);
        while(n>0){
            if(n%2==1){
                result = result.multiply(temp,do_mod);
            }
            temp=temp.multiply(temp,do_mod);
            n=n/2;
        }
        return move(result);
    }
    void show(){
        for(ll x=0;x<rows;x++){
            for(ll y=0;y<cols;y++){
                cout<<mat[x][y]<<"\t";
            }
            cout<<endl;
        }
    }
};

ll my_pow(ll a,ll b){
    if(b==0){
        return 1;
    }
    ll temp=my_pow(a,b/2);
    temp=(temp*temp)%mod;
    if(b%2==1){
        temp=(temp*a)%mod;
    }
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<vector<ll>> ar1={{1,1,-6,0,0},
                            {0,1,2,0,0},
                            {0,0,1,1,0},
                            {0,0,1,0,1},
                            {0,0,1,0,0}};
    vector<vector<ll>> ar2={{1,1,0},
                            {1,0,1},
                            {1,0,0}};
    Matrix m1=Matrix(ar1);
    Matrix m2=Matrix(ar2);
    return 0;
}