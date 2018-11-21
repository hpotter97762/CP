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
    string s;
    cin>>s;
    ll n=s.size();
    if(n==1){
        cout<<1<<'\n';
        return 0;
    }
    s+=s;
    ll nn=n*2;
    ll ans=0;
    for(ll i=0;i<nn;){
        for(ll j=i+1;;++j){
            // cout<<j<<' '<<j%n<<' '<<i<<'\n';
            if(j==nn||j%n==i){
                ans=max(ans,j-i);
                // cout<<j-i<<'\n';
                // cout<<"h"<<j<<' '<<i<<' '<<j-i<<'\n';
                i=nn;
                break;
            }
            if(s[j]==s[j-1]){
                ans=max(ans,j-i);
                // cout<<j-i<<'\n';
                // cout<<"h"<<j<<' '<<i<<' '<<j-i<<'\n';
                i=j;
                break;
            }
        }
        // cout<<ans<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}
