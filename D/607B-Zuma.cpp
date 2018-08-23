#include<bits/stdc++.h>
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
//#define e 2.7182818284590452353602874713526624977572
 
typedef long long int ll;
typedef long double ld;
typedef std::vector<ll> vi;
typedef std::vector<bool> vb;
typedef std::vector<char> vc;
typedef std::pair<ll,ll> pii;
typedef std::vector<pii> vii;

using namespace std;
const ll mod=1e9+7;

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed<<setprecision(25);
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;++i)
        cin>>a[i];
    ll dp[510][510];
    for(ll i=0;i<n;++i)
        for(ll j=0;j<n;++j)
            dp[i][j]=1e18;
    for(int i=0;i<n;++i)
        dp[i][i]=1;
    for(ll sz=2;sz<=n;++sz){
        for(ll i=0;i<n;++i){
            ll j=i+sz-1;
            if(j>=n)
                break;
            for(ll k=i;k<j;++k){
                dp[i][j]=min(dp[i][k]+dp[k+1][j],dp[i][j]);
            }
            if(a[i]==a[j])
                dp[i][j]=min(dp[i][j],((i<j-1)?dp[i+1][j-1]:1LL));
        }
    }
    cout<<dp[0][n-1]<<'\n';
    return 0;
}
