#include<bits/stdc++.h>
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
//#define e 2.7182818284590452353602874713526624977572
 
typedef long long int ll;
typedef long double ld;
typedef std::vector<ll> vi;
typedef std::vector<bool> vb;
typedef std::vector<char> vc;
typedef std::pair<ll,ll> pii;
typedef std::vector<pii> vii;

using namespace std;
const ll mod=1e9+7;

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed<<setprecision(25);
    ll n;
    cin>>n;
    vii a(n);
    for(int i=0;i<n;++i)
        cin>>a[i].fs>>a[i].sc;
    ll l,rr,ll1,rr1;
    l=rr=0;
    for(int i=0;i<n;++i){
        if(a[l].fs<=a[i].fs)
            l=i;
        if(a[rr].sc>=a[i].sc)
            rr=i;
    }
    a.push_back({-1,-1});
    a.push_back({1e18,1e18});
    ll1=n,rr1=n+1;
    for(int i=0;i<n;++i){
        if(a[ll1].fs<=a[i].fs&&i!=l)
            ll1=i;
        if(a[rr1].sc>=a[i].sc&&i!=rr)
            rr1=i;
    }
    // cout<<l<<' '<<rr<<' '<<ll1<<' '<<rr1<<'\n';
    ll ans;
    if(rr==l)
        ans=a[rr1].sc-a[ll1].fs;
    else
        ans=max(a[rr1].sc-a[l].fs,a[rr].sc-a[ll1].fs);
    cout<<max(ans,0LL)<<'\n';
    return 0;
}