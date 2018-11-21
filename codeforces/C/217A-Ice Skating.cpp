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
vector<vector<map<ll,bool>>>adj;
map<pair<ll,ll>,bool> vis;

void dfs(ll x,ll y){
    vis[{x,y}]=1;
    for(auto i:adj[0][x]){
        if(!vis[{x,i.fs}])
            dfs(x,i.fs);
    }
    for(auto i:adj[1][y]){
        if(!vis[{i.fs,y}])
            dfs(i.fs,y);
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,a,b;
    cin>>n;
    adj.resize(2,vector<map<ll,bool>>(1000));
    vii pt(n);
    for(int i=0;i<n;++i){
        cin>>a>>b;
        --a,--b;
        pt[i]={a,b};
        adj[0][a][b]=1;
        adj[1][b][a]=1;
    }
    int cnt=0;
    for(int i=0;i<n;++i){
        if(!vis[pt[i]]){
            cnt++;
            dfs(pt[i].fs,pt[i].sc);
        }
    }
    cout<<cnt-1<<'\n';
    return 0;
}