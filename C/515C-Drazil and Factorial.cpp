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
vector<unordered_map<int,ll>> adj;
vii edge;
vi wt;

bool dfs1(int a,int b){
    bool k=0;
    for(auto it=adj[a].begin();it!=adj[a].end();++it){
        if(it->fs==b)
            return true;
        if(it->fs!=0&&k==false)
            k|=dfs1(it->fs,b);
    }
    return k;
}

void dfs(int a,ll b){
    wt[a]=b;
    for(auto it=adj[a].begin();it!=adj[a].end();++it){
        if(it->fs!=0)
            dfs(it->fs,b+it->sc);
    }
}
int a[10][4]={{0,0,0,0},{0,0,0,0},{1,0,0,0},{1,1,0,0},{3,1,0,0},
            {3,1,1,0},{4,2,1,0},{4,2,1,1},{7,2,1,1},{7,4,1,1}};
vector<int> po(4,0);
char ap[]="2357";
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=read_int();
    char c;
    for(int i=0;i<n;++i){
        c=getchar();
        c-='0';
        for(int i=0;i<4;++i)
            po[i]+=a[c][i];
    }
    string ans;
    while(1){
        int i,j;
        for(i=3;i>=0;--i){
            if(po[i])
                break;
        }
        if(i==-1)
            break;
        ans+=ap[i];
        for(j=0;j<4;++j){
            po[j]-=a[ap[i]-'0'][j];
            if(po[j]<0)
                break;
        }
        /*if(j!=4){
            ans.pop_back();
            break;
        }*/
    }
    cout<<ans<<'\n';
    return 0;
}