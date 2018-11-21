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

ll a[200005];
bool cmp(ll i,ll j){
    return a[i]<a[j];
}

int main(){
    INIT
    ll n;
    cin>>n;
    vi z,neg,pos;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i){
        if(a[i]==0)
            z.push_back(i);
        else if(a[i]<0)
            neg.push_back(i);
        else
            pos.push_back(i);
    }
    ll curr=-1,num=0;
    if(z.size()!=0){
        curr=z[0];
        for(int i=1;i<z.size();++i){
            cout<<1<<' '<<curr+1<<' '<<z[i]+1<<'\n';
            ++num;
            curr=z[i];
        }
    }
    sort(neg.begin(),neg.end(),cmp);
    if(neg.size()%2){
        if(curr==-1)
            curr=neg.back();
        else{
            cout<<1<<' '<<curr+1<<' '<<neg.back()+1<<'\n';
            ++num;
            curr=neg.back();
        }
    }
    if(curr!=-1&&n>num+1)
        cout<<2<<' '<<curr+1<<'\n';
    if(neg.size()>1)
        curr=neg[0];
    else if(pos.size()!=0)
        curr=pos[0];
    ll tp=neg.size();
    if(neg.size()%2)
        tp--;
    for(int i=1;i<tp;++i){
        cout<<1<<' '<<curr+1<<' '<<neg[i]+1<<'\n';
        curr=neg[i];
    }
    for(auto k:pos){
        if(curr!=k){
            cout<<1<<' '<<curr+1<<' '<<k+1<<'\n';
            curr=k;
        }
    }
    return 0;
}
