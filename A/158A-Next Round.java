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
int mod=1e9+7;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    int i;
    for(i=k;i<n;++i){
        if(a[i]!=a[i-1])
            break;
    }
    --i;
    for(;i>=0;--i)
        if(a[i]!=0)
            break;
    cout<<i+1<<'\n';
}