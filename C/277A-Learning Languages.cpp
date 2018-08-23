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
vector<vector<vi>>adj;
map<pair<ll,ll>,bool> vis;
vi emp;

void dfs(ll x,ll y){
    // cout<<x<<' '<<y<<'\n';
    vis[{x,y}]=1;
    emp[x]=1;
    for(auto i:adj[0][x]){
        if(!vis[{x,i}])
            dfs(x,i);
    }
    for(auto i:adj[1][y]){
        if(!vis[{i,y}])
            dfs(i,y);
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,a,b,m;
    cin>>n>>m;
    adj.resize(2,vector<vi>(max(n,m)));
    emp.resize(n,0);
    ll tot=0;
    for(int i=0;i<n;++i){
        ll num;
        cin>>num;
        tot+=num;
        for(int j=0;j<num;++j){
            cin>>b;
            a=i;
            --b;
            adj[0][a].push_back(b);
            adj[1][b].push_back(a);
        }
    }
    // for(int j=0;j<n;++j)
    //     for(int k=0;k<adj[0][j].size();++k)
    //         cout<<0<<' '<<j<<' '<<adj[0][j][k]<<'\n';
    // for(int j=0;j<n;++j)
    //     for(int k=0;k<adj[1][j].size();++k)
    //         cout<<1<<' '<<j<<' '<<adj[1][j][k]<<'\n';
    int cnt=0;
    for(int i=0;i<n;++i){
        if(!emp[i]){
            // cout<<'\n';
            cnt++;
            if(adj[0][i].size()>0)
                dfs(i,adj[0][i][0]);
        }
    }
    cout<<(tot>0?cnt-1:cnt)<<'\n';
    return 0;
}