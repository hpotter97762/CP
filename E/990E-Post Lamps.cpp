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

ll get(ll jmp){

}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m,n,k,s;
    cin>>n>>m>>k;
    vb b(1e6+5,0);
    vi a(n);
    for(int i=0;i<m;++i){
        cin>>s;
        b[s]=1;
    }
    for(int i=0;i<k;++i)
        cin>>a[i];
    if(b[0]){
        cout<<"-1\n";
        return 0;
    }
    vi prev(n);
    for(int i=0;i<n;++i){
        if(b[i])
            prev[i]=prev[i-1];
        else
            prev[i]=i;
    }
    ll ans=1e18;
    for(int i=0;i<k;++i){
        ll r=0,j=-1,cnt=0,jmp=i+1;
        while(r<n){
            ll p=r;
            ++cnt;
            r+=jmp;
            if(r<n)
                r=prev[r];
            if(r<=p){
                cnt=1e18;
                break;
            }
        }
        if(cnt!=1e18)
            ans=min(ans,a[i]*cnt);
    }
    cout<<(ans==1e18?-1:ans)<<'\n';
    return 0;
}