#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fs first
#define sc second
#define INIT std::ios_base::sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(25);
#define pi 3.141592653589793238462643383279502884197
//#define e 2.7182818284590452353602874713526624977572
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef std::vector<ll> vi;
typedef std::vector<bool> vb;
typedef std::vector<char> vc;
typedef std::pair<ll,ll> pii;
typedef std::vector<pii> vii;
using namespace std;
using namespace __gnu_pbds;
//Debugging Code
template<typename T>
void prn(T first) {
    cout << first << "\n";
}
template<typename T, typename... Args>
void prn(T first, Args... args) {
    cout << first << " ";
    prn(args...);
}
//HashMap
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<ll,ll,chash> hashMap;
 
//Random Number Generator
inline ull Rand(ll a,ll b){
    uniform_int_distribution<>dis(a,b);
    mt19937_64 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
    return dis(gen);
}
//##########################################################################################//
//Actual code starts here//
const ll mod=1e9+7;
ll par[1000005],rk[1000005];
 
ll getParent(ll i){
    if(i!=par[i])  return par[i]=getParent(par[i]);
    return i;
}
 
void addEdge(ll i,ll j){
    ll pari=getParent(i),parj=getParent(j);
    // cout<<i<<' '<<j<<' '<<pari<<' '<<parj<<' '<<rk[pari]<<' '<<rk[parj]<<"h\n";
    if(pari!=parj){
        if(rk[pari]>rk[parj])
            par[parj]=pari;
        else if(rk[pari]==rk[parj]){
            par[parj]=pari;
            rk[pari]++;
        }
        else
            par[pari]=parj;
    }
}
 
int main(){
    INIT;
    ll prime[100000];
    ll fac[100001],p=0;
    for(int i=2;i<1e5;++i){
        if(fac[i]==0){
            prime[p++]=i;
            for(int j=i;j<1e5;j+=i)
                fac[j]=1;
        }
    }
    ll t;
    cin>>t;
    while(t--){
        ll m,n;
        cin>>m>>n;
        ll is[n-m+1];
        for(auto &i:is)
            i=0;
        for(int i=0;prime[i]*prime[i]<=n;++i){
            ll j=m+((prime[i]-m%prime[i]))%prime[i];
            if(j==prime[i])
                j+=prime[i];
            for(;j<=n;j+=prime[i]){
                is[j-m]=1;
            }
        }
        for(int i=0;i<=n-m;++i){
            if(is[i]==0)
                cout<<m+i<<'\n';
        }
    }
    return 0;
} 
