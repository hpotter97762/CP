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
vector<set<ll>> adj;
ll del[100005]={0},leg[100005]={0};

void dfs(ll src,ll par){
    if(adj[src].size()>2){
        leg[src]++;
        return;
    }
    del[src]=1;
    for(auto i:adj[src]){
        if(i!=par)
            dfs(i,src);
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed<<setprecision(25);
    ll n,x,y;
    cin>>n;
    adj.resize(n);
    for(int i=0;i<100005;++i)
        del[i]=leg[i]=0;
    for(int i=1;i<n;++i){
        cin>>x>>y;
        --x,--y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    for(int i=0;i<n;++i){
        if(adj[i].size()==1){
            dfs(i,-1);
        }
    }
    bool flag=true;
    for(int i=0;i<n;++i){
        if(del[i])
            continue;
        ll cnt=0;
        for(auto j:adj[i]){
            if(del[j])
                continue;
            if(adj[j].size()-min(2LL,leg[j])>1)
                cnt++;
        }
        if(cnt>2)
            flag=false;
    }
    if(flag)
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
