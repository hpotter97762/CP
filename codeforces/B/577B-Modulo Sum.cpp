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
    ll n,m;
    cin>>n>>m;
    vi a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
        a[i]%=m;
    }
    if(n>m)
        cout<<"YES\n";
    else{
        vb b(m,0),c(m);
        for(int i=0;i<n&&!b[0];++i){
            fill(c.begin(),c.end(),0);
            for(int j=0;j<m&&!b[0];++j){
                if(b[j]&&!c[j]){
                    if(!b[(a[i]+j)%m])
                        c[(a[i]+j)%m]=1;
                    b[(a[i]+j)%m]=1;
                }
            }
            b[a[i]]=1;
        }
        if(b[0])
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
