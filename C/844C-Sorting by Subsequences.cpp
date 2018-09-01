#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define mp make_pair
#define pii pair<ll,ll>
#define vii vector<pair<ll,ll> >
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
//#define e 2.7182818284590452353602874713526624977572

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

vi adj;
vector<vi>ans;
vb vis;

void dfs(ll i,vi &a){
    vis[i]=true;
    a.push_back(i);
    if(!vis[adj[i]])
        dfs(adj[i],a);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=read_ll();
    vii a(n);
    adj.resize(n);
    vis.resize(n,false);
    for(int i=0;i<n;++i){
        a[i]=make_pair(read_ll(),i);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i){
        adj[a[i].sc]=i;
    }
    for(int i=0;i<n;++i){
        if(vis[i]==false){
            vi ans1;
            dfs(i,ans1);
            ans.push_back(ans1);
        }
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();++i){
        cout<<ans[i].size()<<" ";
        for(int j=0;j<ans[i].size();++j)
            cout<<ans[i][j]+1<<" ";
        cout<<'\n';
    }
    return 0;
}