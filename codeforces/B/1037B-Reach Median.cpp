#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return (x ^ RANDOM); }
};
gp_hash_table<ll,ll,chash> aBetterHashMap;
const ll mod=1e9+7;

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed<<setprecision(25);
    ll n,s;
    cin>>n>>s;
    vi a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    if(n==1){
        cout<<abs(a[0]-s)<<'\n';
        return 0;
    }
    ll i=0,ans=0;
    sort(a.begin(),a.end());
    for(i=0;i<n/2;++i)
        ans+=max(0ll,a[i]-s);
    ans+=abs(a[i]-s);
    ++i;
    for(;i<n;++i){
        ans+=max(0ll,s-a[i]);
    }
    cout<<ans<<'\n';
    return 0;
}
