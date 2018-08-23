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
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        int j=n-1,i=0;
        while(i<j){
            if(abs(s[i]-s[j])==0||abs(s[i]-s[j])==2)
                ++i,--j;
            else
                break;
        }
        if(i<j)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}
