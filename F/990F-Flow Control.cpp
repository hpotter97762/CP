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

vector<map<ll,ll>>adj;
vi vis,a;

int dfs(int q){
    vis[q]=1;
    ll ret=0;
    for(auto i:adj[q]){
        if(!vis[i.fs]){
            adj[q][i.fs]=dfs(i.fs);
            adj[i.fs][q]=-adj[q][i.fs];
            ret+=adj[i.fs][q];
        }
    }
    return a[q]-ret;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n;
    a.resize(n);
    adj.resize(n);
    vis.resize(n,0);
    for(int i=0;i<n;++i)
        cin>>a[i];
    cin>>m;
    vii edge(m);
    vi inc(n,0);
    for(int i=0;i<m;++i){
        cin>>edge[i].fs>>edge[i].sc;
        --edge[i].fs,--edge[i].sc;
        adj[edge[i].fs][edge[i].sc]=adj[edge[i].sc][edge[i].fs]=0;
    }
    ll sum=0;
    for(int i=0;i<n;++i)
        sum+=a[i];
    if(sum!=0){
        cout<<"Impossible";
        return 0;
    }
    cout<<"Possible\n";
    dfs(0);
    for(int i=0;i<m;++i)
        cout<<adj[edge[i].fs][edge[i].sc]<<'\n';
    return 0;
}