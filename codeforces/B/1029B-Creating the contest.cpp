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
    vi a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    ll ans=0;
    for(int i=0;i<n;){
        ll j=i+1;
        while(j<n&&a[j-1]*2>=a[j])++j;
        ans=max(ans,j-i);
        i=j;
    }
    cout<<ans<<'\n';
    return 0;
}