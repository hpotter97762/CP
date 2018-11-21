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
vector<map<ll,bool> > adj;

ll gcd(ll a ,ll b){
    while(b!=0){
        ll tmp=a;
        a=b;
        b=tmp%b;
    }
    return a;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    ll g=a[0];
    for(int i=0;i<n;++i){
        g=gcd(g,a[i]);
    }
    for(int i=0;i<n;++i){
        ll tp=a[i]/g;
        while(tp%2==0) tp/=2;
        while(tp%3==0) tp/=3;
        if(tp!=1){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";
    return 0;
}