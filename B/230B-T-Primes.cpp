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
const int mod=1e9+7;
ll mx=1e6+1e4;
vb fac(mx,true);

void init(){
    fac[0]=fac[1]=false;
    for(ll i=2;i*i<mx;++i){
        if(fac[i]){
        	for(ll j=i*2;j<mx;j+=i){
        		fac[j]=false;
        	}
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll a;
    init();
    while(n--){
    	cin>>a;
    	ll b=ceil(sqrt(a));
    	if(b*b==a&&fac[b])
    		cout<<"YES\n";
    	else
    		cout<<"NO\n";
    }
}