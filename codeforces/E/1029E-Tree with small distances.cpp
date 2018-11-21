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

//Random Number Generator
inline ull Rand(ll a,ll b){
    uniform_int_distribution<>dis(a,b);
    mt19937_64 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
    return dis(gen);
}

//HashMap
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return (x ^ RANDOM); }
};
gp_hash_table<int,ll,chash> mp;
const ll mod=1e9+7;

//*****************************************************************************************//
//Actual code begins here
set<pii> tst;
vi adj[200005];
ll dist[200005];
ll pr[200005];

void dfs(ll src,ll par=-1,ll dst=0){
    tst.insert({dst,src});
    pr[src]=par;
    dist[src]=dst;
    for(auto i:adj[src])
        if(i!=par)
            dfs(i,src,dst+1);
}

int main(){
    INIT
    ll n,a,b;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>a>>b;
        --a,--b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0);
    // for(auto i:tst)
    //     cout<<i.fs<<' '<<i.sc<<'\n';
    // cout<<'\n';
    ll ans=0;
    for(auto it=tst.rbegin();it!=tst.rend();++it){
        if(dist[it->sc]<3)
            continue;
        // cout<<it->fs<<' '<<it->sc<<'\n';
        ll pt=pr[it->sc];
        dist[pt]=1;
        ++ans;
        for(auto k:adj[pt])
            dist[k]=min(dist[k],2ll);
    }
    cout<<ans<<'\n';
    return 0;
}
