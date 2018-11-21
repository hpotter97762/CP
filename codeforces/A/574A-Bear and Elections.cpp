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
    ll n;
    cin>>n;
    vi a(n);
    ll mx=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        mx=max(a[i],mx);
    }
    ll vot=a[0];
    sort(a.begin(),a.end());
    if(a[n-1]==vot&&a[n-2]!=vot){
        cout<<0<<'\n';
        return 0;
    }
    for(int i=0;i<mx-vot+2;++i){
        ll tmp=vot+i,bribe=0,j;
        for(j=n-1;j>=0;--j){
            if(a[j]<tmp)
                break;
            bribe+=a[j]-tmp+1;
            if(bribe>i)
                break;
            // cout<<bribe<<'\n';
        }
        if(bribe<=i){
            cout<<i;
            break;
        }
    }
    return 0;
}