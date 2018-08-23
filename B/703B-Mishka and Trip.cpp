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
    ll n,k,a;
    cin>>n>>k;
    vi b(n);
    for(int i=0;i<n;++i)
        cin>>b[i];
    vb cap(n,0);
    for(int i=0;i<k;++i){
        cin>>a;
        cap[a-1]=1;
    }
    ll ans=0,sum=0,capsum=0;
    for(int i=0;i<n;++i){
        sum+=b[i];
        if(cap[i])
            capsum+=b[i];
    }
    // cout<<sum<<' '<<capsum<<'\n';
    for(int i=0;i<n;++i){
        if(cap[i]){
            ans+=(sum-b[i])*b[i];
        }
        else{
            ans+=(capsum*b[i]);
            if(!cap[(i+1)%n])
                ans+=b[i]*b[(i+1)%n];
            if(!cap[(i-1+n)%n])
                ans+=b[i]*b[(i-1+n)%n];
        }
    }
    cout<<ans/2<<'\n';
    return 0;
}