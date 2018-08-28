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
gp_hash_table<int,ll,chash> mp[10];
ll a[200005];
ll n,k;
const ll mod=1e9+7;

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed<<setprecision(25);
    cin>>n>>k;
    for(ll i=0;i<n;++i)
        cin>>a[i];
    for(ll i=0;i<n;++i){
        ll tmp=a[i]%k;
        for(ll q=0;q<10;++q){
            tmp=(tmp*10)%k;
            mp[q][tmp]++;
        }
    }
    ll ans=0;
    for(ll i=0;i<n;++i){
        ll tp=(k-(a[i]%k))%k;
        ll ndig=0,tmp=a[i],st=a[i];
        while(st!=0)st/=10,tmp=(tmp*10)%k,ndig++;
        if(mp[ndig-1].find(tp)!=mp[ndig-1].end())
            ans+=mp[ndig-1][tp];
        if(tmp==tp)
            ans--;
    }
    cout<<ans<<'\n';
    return 0;
}