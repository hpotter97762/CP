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
const int mod=1000000007;

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

bool cmp(pii a,pii b){
    if(a.fs==b.fs)
        return a.sc<b.sc;
    return a.fs>b.fs;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl(),k=rl();
    vii c(n+1);
    vi cons(n+1);
    c[0]={LONG_MAX,0};
    for(int i=1;i<=n;++i){
        c[i]=make_pair(rl(),i);
        cons[i]=c[i].fs;
    }
    vi ans(n+1,-1);
    ll j=1;
    sort(c.begin(),c.end(),cmp);
    for(int i=1;i<=n;++i){
        while(ans[j]>0)++j;
        ll tp;
        if(j+k<c[i].sc)
            tp=c[i].sc-k;
        else
            tp=j;
        while(ans[tp]>0)++j;
        ans[tp]=c[i].sc;
    }
    vi ans1(n+1);
    for(int i=1;i<=n;++i){
        ans1[ans[i]]=i;
    }
    ll an=0;
    for(int i=1;i<=n;++i)
        an+=(ans1[i]-i+k)*cons[i];
    cout<<an<<'\n';
    for(int i=1;i<=n;++i)
        cout<<ans1[i]+k<<" ";
    cout<<'\n';
    return 0;
}