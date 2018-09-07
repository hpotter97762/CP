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
    ll n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    ll ans=0,flag=0;
    for(int i=1;i<n;++i){
        if(a[i]!=b[i]&&a[i-1]!=b[i-1]&&a[i]!=a[i-1]){
            if(i==n-1)
                flag=1;
            ans++,++i;
        }
        else if(a[i-1]!=b[i-1])
            ans++;
    }
    if(a[n-1]!=b[n-1]&&!flag)
        ans++;
    cout<<ans<<'\n';
    return 0;
}
