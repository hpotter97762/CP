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
    int operator()(int x) const { return (x ^ RANDOM); }
};
// gp_hash_table<int,ll,chash> mp;
const ll mod=1e9+7;

//Random Number Generator
inline ull Rand(ll a,ll b){
    uniform_int_distribution<>dis(a,b);
    mt19937_64 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
    return dis(gen);
}
//##########################################################################################//
//Actual code starts here//

int main(){
    INIT
    set<ll>mp;
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vi a(n+1);
    a[0]=0;
    for(int i=1;i<=n;++i){
        a[i]=a[i-1]+s[i-1]-'0';
        mp.insert(a[i]);
    }
    if(a[n]==0){
        cout<<"YES\n";
        return 0;
    }
    for(int i=1;i<n;++i){
        if(a[i]==0)
            continue;
        if(a[n]%a[i]==0&&a[n]!=a[i]){
            ll j=a[i];
            while(j<a[n]&&mp.find(j)!=mp.end())j+=a[i];
            if(j==a[n]){
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
    return 0;
}
