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
vi a,c,vis;
ll ans=0,start;

void update(ll src,ll mn,ll st){
    if(src==st&&start==1){
        ans+=mn;
        return;
    }
    start=1;
    update(a[src],min(mn,c[src]),st);
}

void dfs(ll src,ll par){
    if(vis[src]==par){
        start=0;
        update(src,c[src],src);
        return;
    }
    if(vis[src]!=-1)
        return;
    vis[src]=par;
    dfs(a[src],par);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    a.resize(n);
    c.resize(n);
    vis.resize(n,-1);
    for(int i=0;i<n;++i)
        cin>>c[i];
    for(int i=0;i<n;++i){
        cin>>a[i];
        --a[i];
    }
    for(int i=0;i<n;++i){
        if(vis[i]==-1)
            dfs(i,i);
    }
    cout<<ans<<'\n';
    return 0;
}
