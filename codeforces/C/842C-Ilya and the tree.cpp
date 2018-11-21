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
//#define e 2.7182818284590452353602874713526624977572

using namespace std;
const int mod=1000000007,p=200002;

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

struct obj{
    ll val;
    list<int>adj;
};

vi ans;
vector<obj> tree;
vb vis;
vector<vi> fact(p);
vi cont(p,0);

void init(){
    for(int i=1;i<p;++i){
        for(int j=i;j<p;j+=i){
            fact[j].push_back(i);
        }
    }
}

ll gcd(ll a,ll b){
    if(b==0)
        return a;
    while(a%b){
        ll tmp=a%b;
        a=b;
        b=tmp;
    }
    return b;
}
void traverse(ll p,ll g,ll cnt){
    vis[p]=1;
    ll val=tree[p].val,i;
    for(int j=0;j<fact[val].size();++j){
        cont[fact[val][j]]++;
    }
    for(i=fact[val].size()-1;i>0;--i){
        if(cont[fact[val][i]]>cnt-2)
            break;
    }
    ans[p]=max(fact[val][i],g);
    g=gcd(g,val),++cnt;
    for(auto it=tree[p].adj.begin();it!=tree[p].adj.end();++it){
        if(!vis[*it])
            traverse(*it,g,cnt);
    }
    for(int j=0;j<fact[val].size();++j){
        cont[fact[val][j]]--;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    ll n=read_ll(),x,y;
    tree.resize(n);
    ans.resize(n);
    vis.resize(n,0);
    for(int i=0;i<n;++i)
        tree[i].val=read_ll();
    for(int i=0;i<n-1;++i){
        x=read_ll(),y=read_ll();
        tree[x-1].adj.push_back(y-1);
        tree[y-1].adj.push_back(x-1);
    }
    traverse(0,0,1);
    for(int i=0;i<n;++i)
        cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
}