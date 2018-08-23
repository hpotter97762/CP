#include<bits/stdc++.h>
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
//#define e 2.7182818284590452353602874713526624977572
 
typedef unsigned long long int ll;
typedef long double ld;
typedef std::vector<ll> vi;
typedef std::vector<bool> vb;
typedef std::vector<char> vc;
typedef std::pair<ll,ll> pii;
typedef std::vector<pii> vii;

using namespace std;
const ll mod=1e9+7;

void fun(ll tp,set<ll>&dp){
    ll n=tp;
    for(int i=2;i*i<=n;++i){
        if(tp%i==0)dp.insert(i);
        while(tp%i==0)tp/=i;
    }
    if(tp!=1)
        dp.insert(tp);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<ll>dp;
    ll n;
    cin>>n;
    vii a(n);
    for(int i=0;i<n;++i)
        cin>>a[i].fs>>a[i].sc;
    fun(a[0].fs,dp);
    fun(a[0].sc,dp);
    for(int i=1;i<n;++i){
        for(auto it=dp.begin();it!=dp.end();){
            ll k=*it;
            if(((a[i].fs%k)!=0)&&((a[i].sc%k)!=0)){
                ++it;
                dp.erase(k);
            }
            else
                ++it;
        }
    }
    if(dp.size()!=0)
        cout<<*dp.begin()<<'\n';
    else
        cout<<-1<<'\n';
    return 0;
}
