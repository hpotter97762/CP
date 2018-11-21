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

//HashMap
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return (x ^ RANDOM); }
};
gp_hash_table<ll,ll,chash> aBetterHashMap;
const ll mod=1e9+7;

//Random Number Generator
inline ull Rand(ll a,ll b){
    uniform_int_distribution<>dis(a,b);
    mt19937_64 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
    return dis(gen);
}

bool chk(ll a,ll b){
    cout<<a<<' '<<b<<'\n';
    fflush(stdout);
    string s;
    cin>>s;
    if(s[0]=='Y')
        return true;
    else
        return false;
}

int main(){
    INIT
    ll n,t;
    cin>>n>>t;
    ll a[n+1],x[n+1];
    for(int i=1;i<=n;++i)
        cin>>a[i];
    set<ll> vec[n+1];
    for(int i=1;i<=n;++i){
        cin>>x[i];
        vec[x[i]].insert(a[i]);
    }
    ll pre=3e18;
    ll ans[n+1],j=n,flag=n;
    for(int i=n;i>0;--i){
        if(vec[i].size()==0)
            continue;
        if(flag!=i){
            cout<<"No\n";
            return 0;
        }
        ll tmp=*vec[i].begin()+t;
        if((pre-tmp)<(ll)vec[i].size()){
            cout<<"No\n";
            return 0;
        }
        ll en=j;
        for(int k=0;k<vec[i].size();++k)
            ans[j--]=--pre;
        for(int k=j+1;k<en;++k){
            if(a[k+1]+t>ans[k]){
                cout<<"No\n";
                return 0;
            }
        }
        pre=tmp;
        flag-=vec[i].size();
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}
