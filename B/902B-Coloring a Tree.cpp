#include<bits/stdc++.h>
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
#define e 2.7182818284590452353602874713526624977572

typedef long long int ll;
typedef long double ld;
typedef std::vector<ll> vi;
typedef std::vector<bool> vb;
typedef std::vector<char> vc;
typedef std::pair<ll,ll> pii;
typedef std::vector<pii> vii;

using namespace std;
const int mod=1e9+7;

inline ll rl(){
    ll res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}

inline void read(string &s){
    s="";
    char c=getchar();
    while(c!='\n'&&c!=' '){
        s+=c;
        c=getchar();
    }
}
vector<vi> adj;
vi vis,col,col1,vis1;
ll ans=0,n;

void dfs1(ll a,ll b){
    vis1[a]=1;
    col1[a]=b;
    for(auto i:adj[a])
        if(!vis1[i])
            dfs1(i,b);
}

void dfs(ll a){
    vis[a]=1;
    if(col1[a]!=col[a]){
        ++ans;
        for(int i=0;i<n;++i)
            vis1[i]=0;
        vis1[a]=1;
        for(auto i:adj[a])
            if(!vis[i])
                dfs1(i,col[a]);
    }
    for(auto i:adj[a])
        if(!vis[i])
            dfs(i);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	n=rl();
	adj.resize(n);
	col1.resize(n,0);
	col.resize(n);
	vis.resize(n,0);
	vis1.resize(n);
	for(int i=1;i<n;++i){
        ll tmp=rl()-1;
        if(tmp!=i){
            adj[i].push_back(tmp);
            adj[tmp].push_back(i);
        }
    }
    for(int i=0;i<n;++i)
        col[i]=rl();
    dfs(0);
    cout<<ans<<'\n';
	return 0;
}