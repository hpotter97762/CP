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
struct oper{
    ll l,r,d;
};

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll m,k,n;
    cin>>n>>m>>k;
    vi a(n);
    for(int i=0;i<n;++i)
        cin>>a[i];
    vector<oper> op(m);
    for(int i=0;i<m;++i){
        cin>>op[i].l>>op[i].r>>op[i].d;
        op[i].l--,op[i].r--;
    }
    vi tmp(m+1);
    ll q,b;
    for(int i=0;i<k;++i){
        cin>>q>>b;
        --q,--b;
        tmp[q]++,tmp[b+1]--;
    }
    q=0;
    for(int i=0;i<m;++i){
        q+=tmp[i];
        op[i].d*=q;
    }
    tmp.resize(n+1,0);
    fill(tmp.begin(),tmp.end(),0);
    for(int i=0;i<m;++i){
        tmp[op[i].l]+=op[i].d;
        tmp[op[i].r+1]-=op[i].d;
    }
    q=0;
    for(int i=0;i<n;++i){
        q+=tmp[i];
        cout<<a[i]+q<<' ';
    }
    return 0;
}