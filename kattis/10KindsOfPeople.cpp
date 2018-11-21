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
    for(int i=0;i<1000005;++i)
        par[i]=i,rk[i]=0;
    ll r,c;
    cin>>r>>c;
    vector<string> s(r);
    for(int i=0;i<r;++i)
        cin>>s[i];
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            if(i<r-1&&s[i][j]==s[i+1][j])
                addEdge(c*i+j,c*(i+1)+j);
            if(j<c-1&&s[i][j]==s[i][j+1])
                addEdge(c*i+j,c*i+j+1);
        }
    }
    ll q;
    cin>>q;
    while(q--){
        ll i,j,k,l;
        cin>>i>>j>>k>>l;
        --i,--j,--k,--l;
        i=c*i+j,j=c*k+l;
        ll pari=getParent(i),parj=getParent(j);
        if(pari!=parj)
            cout<<"neither\n";
        else if(s[k][l]=='0')
            cout<<"binary\n";
        else
            cout<<"decimal\n";
    }
    return 0;
}
