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

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,q;
    cin>>n>>q;
    while(q--){
        ll x,y;
        cin>>x>>y;
        --x,--y;
        ll ans1=n*(ll)(x/2);
        ll ans2=ans1+(n*n)/2;
        ans2+=n%2;
        // cout<<ans1<<' '<<ans2<<'\n';
        if(x%2){
            ans1+=(n/2);
            ans1+=(n%2);
            ans2+=(n/2);
        }
        // cout<<ans1<<' '<<ans2<<'\n';
        if(x%2==y%2){
            cout<<ans1+(y/2)+1<<'\n';
        }
        else{
            cout<<ans2+(y/2)+1<<'\n';
        }
    }
    return 0;
}
