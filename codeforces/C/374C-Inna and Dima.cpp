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
const int mod=1e9+7;

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
vector<vc>mat;
vector<vi>vis,out;
vector<vb> ot;
char nxt[5]="DIMA";
ll num,n,m,k,q;

ll dfs(ll i,ll j,ll in){
    //cout<<i<<" "<<j<<'\n';
    if(vis[i][j]==k&&!ot[i][j])
        return out[i][j]=1e18;
    if(vis[i][j])
        return out[i][j];
    vis[i][j]=k;
    if(i>0&&mat[i-1][j]==nxt[in])
        out[i][j]=max(out[i][j],dfs(i-1,j,(in+1)%4));
    if(i<n-1&&mat[i+1][j]==nxt[in])
        out[i][j]=max(out[i][j],dfs(i+1,j,(in+1)%4));
    if(j>0&&mat[i][j-1]==nxt[in])
        out[i][j]=max(out[i][j],dfs(i,j-1,(in+1)%4));
    if(j<m-1&&mat[i][j+1]==nxt[in])
        out[i][j]=max(out[i][j],dfs(i,j+1,(in+1)%4));
    if(mat[i][j]=='A'&&out[i][j]!=1e18)
        out[i][j]++;
    ot[i][j]=1;
    return out[i][j];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    n=rl(),m=rl();
    out.resize(n,vi(m,0));
    vis.resize(n,vi(m,0));
    mat.resize(n,vc(m));
    ot.resize(n,vb(m,0));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            mat[i][j]=getchar();
        getchar();
    }
    ll ans=0,cnt,i=0,j=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(!vis[i][j]&&mat[i][j]=='D'){
                k=i*m+j+1;
                out[i][j]=dfs(i,j,1);
            }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(mat[i][j]=='D')
                ans=max(ans,out[i][j]);
            //cout<<out[i][j]<<" ";
        }
        //cout<<'\n';
    }
    if(ans==0)
        cout<<"Poor Dima!\n";
    else if(ans==1e18)
        cout<<"Poor Inna!\n";
    else
        cout<<ans<<'\n';
    return 0;
}