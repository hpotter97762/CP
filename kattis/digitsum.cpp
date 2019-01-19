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
ll chk[10]={0};

inline ll get1(ll a,ll b){
    a=(a+9)%10,b=(b+9)%10;
    // cout<<"hel "<<a<<' '<<b<<'\n';
    if(a<b)
        return 45+chk[a]-chk[b];
    return chk[a]-chk[b];
}

int main(){
    // INIT;
    ll t;
    for(int i=1;i<10;++i)
        chk[i]=i+chk[i-1];
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        ll curr=1,ans=0,cnt=0,cnt1=log10(b);
        ll tst=0;
        while(cnt++<=cnt1){
            for(int i=a;i<=b;++i)
                tst+=(i/curr%10);
            // cout<<"brute"<<tst<<'\n';
            ll tmp=(curr-a%curr)%curr+a;
            ll tp=b-b%curr;
            // cout<<tmp<<' '<<tp<<' '<<curr<<' '<<ans<<'\n';
            ans+=(a/curr%10)*(min(b,tmp)-a);
            // cout<<ans<<'\n';
            if(tmp>b){
                ans+=(a/curr%10);
                curr*=10;
                continue;
            }
            ans+=(b-tp+1)*(tp/curr%10);
            // cout<<ans<<'\n';
            ans+=get1(tp/curr%10,tmp/curr%10)*curr;
            // cout<<ans<<'\n';
            curr*=10;
            ans+=45*(max(0ll,tp-tmp)/curr*curr/10);
            // cout<<ans<<'\n';
        }
        // cout<<"brute"<<tst<<'\n';
        // cout<<a<<' '<<b<<' '<<ans<<'\n';
        cout<<ans<<'\n';
    }
    return 0;
}
