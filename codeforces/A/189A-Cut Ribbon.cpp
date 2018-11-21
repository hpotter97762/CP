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
struct oper{
    ll l,r,d;
};

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    vi a(3);
    cin>>n>>a[0]>>a[1]>>a[2];
    vi dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<=n;++i){
        for(int j=0;j<3;++j){
            if(i-a[j]>=0&&dp[i-a[j]]!=-1)
                dp[i]=max(dp[i],dp[i-a[j]]+1);
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}