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

ll comb(ll a,ll b){
    if(a<b)
        return 0;
    ll ans=1;
    for(int i=1;i<=a;++i)
        ans*=i;
    for(int i=1;i<=b;++i)
        ans/=i;
    for(int i=1;i<=a-b;++i)
        ans/=i;
    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll plus=0,minus=0;
    string s1,s2;
    cin>>s1>>s2;
    for(int i=0;i<s1.size();++i){
        if(s1[i]=='+')
            plus++;
        else
            minus++;
        if(s2[i]=='+')
            plus--;
        if(s2[i]=='-')
            minus--;
    }
    ll tot=plus+minus;
    // cout<<tot<<' '<<plus<<' '<<minus<<'\n';
    cout<<setprecision(20)<<comb(tot,max(plus,minus))/pow(2,tot);
    return 0;
}