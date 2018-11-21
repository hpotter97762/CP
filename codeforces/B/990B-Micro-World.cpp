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

void sort1(vi &a){
    ll n=a.size();
    sort(a.begin(),a.end());
    vi b;
    b.push_back(a[0]);
    for(int i=1;i<n;++i){
        if(a[i]!=a[i-1])
            b.push_back(a[i]);
    }
    a=b;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin>>n>>k;
    vi a(n),b(1e6+2,0);
    for(int i=0;i<n;++i){
        cin>>a[i];
        b[a[i]]++;
    }
    sort1(a);
    ll cnt=0;
    for(int i=1;i<a.size();++i){
        if(a[i]-a[i-1]>k)
            cnt+=b[a[i-1]];
    }
    cout<<cnt+b[a[n-1]]<<'\n';
    return 0;
}