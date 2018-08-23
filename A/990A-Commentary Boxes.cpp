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

struct obj{
    set<int> plus,minus;
};

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    cout<<min(n%m*b,(m-(n%m))*a)<<'\n';
    return 0;
}