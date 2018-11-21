#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<ll,ll>
#define vii vector<pair<ll,ll> >
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
//#define e 2.7182818284590452353602874713526624977572


using namespace std;
const ll mod=1e9+7,phimod=1e9+6;

inline int ri(){
    int res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}

inline ll rl(){
    ll res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}
vector<vi> adj;
vi lev,vis;

void dfs(ll a,ll b){
    if(b==lev.size())
        lev.push_back(1);
    else
        lev[b]++;
    vis[a]=1;
    for(auto i:adj[a]){
        if(!vis[i])
            dfs(i,b+1);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl(),x=rl();
    if(n==1){
        cout<<"YES\n"<<x<<'\n';
        return 0;
    }
    if(n==2){
        if(x==0)
            cout<<"NO\n";
        else
            cout<<"YES\n"<<'0'<<' '<<x<<'\n';
        return 0;
    }
    vi xr;
    while(x){
        xr.push_back(x%2);
        x/=2;
    }
    vi ans(n+1);
    cout<<"YES\n";
    vi cnt(18,0);
    for(int i=0;i<18;++i){
        for(int j=1;j<n-1;++j){
            if((1<<i)&j){
                ans[j]|=(1<<i);
                cnt[i]++;
            }
        }
    }
    for(int i=0;i<18;++i)
    for(int i=0;i<xr.size();++i){
        if(cnt[i]%2!=xr[i])
            ans[n-1]|=(1<<i);
    }
    for(int i=xr.size();i<18;++i){
        if(cnt[i]%2==1)
            ans[n-1]|=(1<<i);
    }
    ans[n-1]|=(1<<18);
    ans[n]=1<<18;
    if(ans[n]==ans[n-1]){
        ans[n-2]|=(1<<19);
        ans[n]|=(1<<19);
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}