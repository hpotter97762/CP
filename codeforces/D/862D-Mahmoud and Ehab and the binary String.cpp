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
ll prv;

void check(string const &s){
    cout<<"? "<<s<<'\n';
    fflush(stdout);
}

ll bins0(string s){
    ll beg=0,las=s.size()-2,nw;
    while(beg<las){
        ll mid=las-(las-beg)/2,l=las;
        for(int i=mid;i<=l;++i)
            s[i]='1';
        check(s);
        nw=rl();
        if(prv-nw<l-mid+1){
            beg=mid;
        }
        else
            las=mid-1;
        for(int i=mid;i<=l;++i)
            s[i]='0';
    }
    return las+1;
}

ll bins1(string s){
    ll beg=0,las=s.size()-2,nw;
    while(beg<las){
        ll mid=las-(las-beg)/2,l=las;
        for(int i=mid;i<=l;++i)
            s[i]='1';
        check(s);
        nw=rl();
        if(nw-prv<l-mid+1){
            beg=mid;
        }
        else
            las=mid-1;
        for(int i=mid;i<=l;++i)
            s[i]='0';
    }
    return las+1;
}

int main()
{
    ll n=rl(),n0,n1;
    string s;
    for(int i=0;i<n;++i)
        s+='0';
    check(s);
    prv=rl();
    s[n-1]='1';
    check(s);
    ll nw=rl();
    if(nw>prv){
        n0=n;
        prv=nw;
        n1=bins1(s);
    }
    else{
        n1=n;
        prv=nw;
        n0=bins0(s);
    }
    cout<<'!'<<" "<<n0<<" "<<n1<<'\n';
    fflush(stdout);
    return 0;
}