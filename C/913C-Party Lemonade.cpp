#include<bits/stdc++.h>
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
//#define e 2.7182818284590452353602874713526624977572

typedef unsigned long long int ll;
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
    ll n,l,tmp,ans=1e19,tp=0;
    cin>>n>>l;
    vi c(n);
    cin>>c[0];
    for(int i=1;i<n;++i){
        cin>>tmp;
        c[i]=min(tmp,2*c[i-1]);
    }
    tmp=1<<(n-1);
    tp=(l/tmp)*c[n-1];
    l%=tmp;
    for(int i=n-1;i>=0;--i){
        if((tmp&l)==0){
            ans=min(ans,tp+c[i]);
        }
        else
            tp+=c[i];
        tmp>>=1;
        // cout<<tp<<' '<<ans<<' '<<tmp<<'\n';
    }
    cout<<min(ans,tp)<<'\n';
    return 0;
}
