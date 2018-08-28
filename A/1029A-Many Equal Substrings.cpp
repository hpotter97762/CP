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
    ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    ll ans=n;
    for(int i=1;i<n;++i){
        int k=i,flag=1;
        for(int j=0;j<n&&k<n;++j,++k){
            if(s[k]!=s[j]){
                flag=0;
                break;
            }
        }
        if(flag){
            ans=i;
            break;
        }
    }
    string sub=s.substr(0,ans);
    for(int i=1;i<k;++i)
        cout<<sub;
    cout<<s<<'\n';
    return 0;
}