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
vi vis;

bool dfs(ll a,ll b){
    if(a==b)
        return true;
    vis[a]=1;
    bool k=false;
    for(auto i:adj[a])
        if(!vis[i])
            k|=dfs(i,b);
    return k;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n=rl(),m=rl();
	vii a(n);
	for(int i=0;i<n;++i)
        a[i].fs=rl(),a[i].sc=rl();
    adj.resize(m+1);
    vis.resize(m+1,0);
    if(a[0].fs!=0){
        cout<<"NO\n";
        return 0;
    }
    for(int i=0;i<n;++i){
        for(int j=a[i].fs+1;j<=a[i].sc;++j){
            adj[a[i].fs].push_back(j);
        }
    }
    if(dfs(0,m))
        cout<<"YES\n";
    else
        cout<<"NO\n";
	return 0;
}