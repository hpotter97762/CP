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
    ll n,k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    vector<vi> dp(n,vi(k+1,1e18)),point(n,vi(k+1));
    for(int i=0;i<=k;++i)
        dp[0][i]=max(0LL,i-a[0]);
    for(int i=1;i<n;++i){
        for(int j=0;j<=k;++j){
            for(int l=k-j;l<=k;++l){
                if(dp[i][j]>dp[i-1][l]+max(0LL,j-a[i])){
                    dp[i][j]=dp[i-1][l]+max(0LL,j-a[i]);
                    point[i][j]=l;
                }
            }
        }
    }
    ll ans=1e18,ind=k;
    for(int i=a[n-1];i<=k;++i){
        if(ans>dp[n-1][i]){
            ans=dp[n-1][i];
            ind=i;
        }
    }
    vi st;
    for(int i=n-1;i>=0;--i)
        st.push_back(ind),ind=point[i][ind];
    cout<<ans<<'\n';
    for(int i=n-1;i>=0;--i)
        cout<<max(a[n-i-1],st[i])<<' ';
    cout<<'\n';
    return 0;
}