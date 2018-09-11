#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fs first
#define sc second
#define INIT std::ios_base::sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(25);
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
using namespace __gnu_pbds;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return (x ^ RANDOM); }
};
gp_hash_table<ll,ll,chash> aBetterHashMap;
gp_hash_table<int,ll,chash> mp;
const ll mod=1e9+7;

bool ask(ll a,ll b){
    cout<<a<<' '<<b<<'\n';
    fflush(stdout);
    string s;
    cin>>s;
    if(a==b&&s[0]=='Y')
        exit(0);
    return s[0]=='Y';
}

int main(){
    // INIT
    ll n,k;
    cin>>n>>k;
    ll beg=1,en=n;
    // cout<<beg<<' '<<en<<"out\n";
    while(beg+5*k<en){
        ll mid=(beg+en)/2;
        // cout<<beg<<' '<<en<<' '<<mid<<"in\n";
        if(ask(beg,mid))
            en=min(n,mid+k),beg=max(beg-k,1ll);
        else
            en=min(n,en+k),beg=max(1ll,mid-k+1);
    }
    // cout<<beg<<' '<<en<<"out\n";
    srand(time(NULL));
    while(1){
        ll random=abs(RANDOM^rand());
        ll kk=random%(en-beg+1)+beg;
        if(ask(kk,kk))
            break;
        beg=max(1ll,beg-k);
        en=min(n,en+k);
        while(beg+5*k<en){
            ll mid=(beg+en)/2;
            // cout<<beg<<' '<<en<<' '<<mid<<"in\n";
            if(ask(beg,mid))
                en=min(n,mid+k),beg=max(beg-k,1ll);
            else
                en=min(n,en+k),beg=max(1ll,mid-k+1);
        }
    }
    return 0;
}
