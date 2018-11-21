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
gp_hash_table<int,vi,chash> mp;
const ll mod=1e9+7;

//Random Number Generator
inline ull Rand(ll a,ll b){
    uniform_int_distribution<>dis(a,b);
    mt19937_64 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
    return dis(gen);
}
//##########################################################################################//
//Actual code starts here

ll c[10000];

struct cmp{
    bool operator()(const int &i,const int &j) const {
        return c[i]<c[j];
    }
};

int main(){
    INIT
    ll n;
    cin>>n;
    string s;
    ll con[n][3]={0};
    set<ll,cmp> tst[3];
    for(int i=0;i<n;++i){
        cin>>c[i]>>s;
        for(auto c:s){
            con[i][c-'A']=1;
            tst[c-'A'].insert(i);
        }
    }
    // for(int i=0;i<3;++i){
    //     for(auto k:tst[i])
    //         cout<<k<<' ';
    //     cout<<'\n';
    // }
    if(tst[0].empty()||tst[1].empty()||tst[2].empty()){
        cout<<-1<<'\n';
        return 0;
    }
    ll ans=1e18,cind=*tst[2].begin();
    for(auto i:tst[0]){
        for(auto j:tst[1]){
            ll tmp=c[i];
            if(i!=j)
                tmp+=c[j];
            if(con[i][2]==0&&con[j][2]==0)
                tmp+=c[cind];
            // cout<<tmp<<'\n';
            ans=min(ans,tmp);
        }
    }
    cout<<ans<<'\n';
    return 0;
}
