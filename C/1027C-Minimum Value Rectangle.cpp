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
        ll n,a;
        cin>>n;
        map<ll,ll>mp;
        for(int i=0;i<n;++i){
            cin>>a;
            mp[a]++;
        }
        vector<double> b;
        for(auto i:mp){
            if(i.sc>1)
                b.push_back(i.fs);
            if(i.sc>3)
                b.push_back(i.fs);
        }
        sort(b.begin(),b.end());
        ld ans=1e18;
        ll l=-1,l2=-1;
        for(int i=1;i<b.size();++i){
            double val=(2*(b[i-1]+b[i]))*(2*(b[i-1]+b[i]))/b[i-1]/b[i];
            if(ans>val)
                ans=val,l=b[i-1],l2=b[i];
        }
        cout<<l<<' '<<l<<' '<<l2<<' '<<l2<<'\n';
    }
    return 0;
}
