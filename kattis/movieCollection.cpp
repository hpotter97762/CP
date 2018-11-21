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
ll sz,nxt;

ll a[1<<21+1];

void print(){
    cout<<"\n############\n";
    for(int i=0;i<sz;++i)
        cout<<a[i]<<' ';
    cout<<"\n############\n";
}

ll sum(ll i){
    ll sum=0,ind=i;
    while(ind>0){
        sum+=a[ind];
        ind=ind&(ind-1);
    }
    return sum;
}

void ad(ll ind,ll val){
    // cout<<ind<<' '<<val<<'\n';
    while(ind<sz){
        a[ind]+=val;
        ind += ( ind & ( -ind ));
    }
}

void update(ll i){
    ad(i,-1);
    ad(nxt++,1);
    // print();
}

int main(){
    // INIT;
    ll t;
    cin>>t;
    while(t--){
        ll m,r;
        cin>>m>>r;
        nxt=m+1;
        sz=m+r;
        while((sz&(sz-1))!=0)
            sz+=(sz&(-sz));
        ++sz;
        // cout<<sz<<'\n';
        for(int i=0;i<sz;++i)
            a[i]=0;
        ll mp1[m+1];
        for(int i=1;i<=m;++i)
            mp1[i]=m-i+1,ad(i,1);
        // print();
        while(r--){
            ll k;
            cin>>k;
            // cout<<mp1[k]<<' ';
            cout<<m-sum(mp1[k])<<' ';
            update(mp1[k]);
            mp1[k]=nxt-1;
        }
        cout<<'\n';
    }
    return 0;
}
