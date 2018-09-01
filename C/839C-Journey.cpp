#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define mp make_pair
#define pii pair<ll,ll>
#define vii vector<pair<ll,ll> >
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
#define e 2.7182818284590452353602874713526624977572
/*
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
*/
using namespace std;
const int mod=1000000007;

int read_int(){
    int res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){
        res=(res<<1)+(res<<3)+c-48;
        c=getchar();
    }
    return neg?-res:res;
}

ll read_ll(){
    ll res=0;
    int neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){
        res=(res<<1)+(res<<3)+c-48;
        c=getchar();
    }
    return neg?-res:res;
}
vector<list<int> >adj;
vb visited;

ld dfs(int sc,ld p,int len){
    visited[sc]=true;
    ld ans=0;
    int ap=adj[sc].size()-1;
    if(sc==0)
        ap++;
    for(auto it=adj[sc].begin();it!=adj[sc].end();++it){
        if(!visited[*it])
            ans+=dfs(*it,p/ap,len+1);
    }
    if(ans==0)
        return p*len;
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=read_int();
    int a,b;
    adj.resize(n);
    visited.resize(n,false);
    for(int i=1;i<n;++i){
        a=read_int(),b=read_int();
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    cout<<std::setprecision(std::numeric_limits<ld>::digits10 + 1)<<dfs(0,1,0)<<'\n';
    return 0;
}