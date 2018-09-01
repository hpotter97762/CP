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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n=rl();
    ll a[n];
    vi cnt(n+1,0),don(n+1,0);
    for(int i=0;i<n;++i){
        a[i]=rl();
        cnt[a[i]]++;
    }
    ll j=1,ans=0;
    for(int i=0;i<n;++i){
        if(cnt[a[i]]==1)
            continue;
        while(cnt[j]>0&&j<n+1)++j;
        cnt[a[i]]--;
        ll tmp=min(a[i],j);
        if(tmp==a[i]&&don[a[i]])
            tmp=j;
        cnt[tmp]++;
        if(a[i]!=tmp)
            ans++;
        a[i]=tmp;
        don[a[i]]=1;
    }
    cout<<ans<<'\n';
    for(int i=0;i<n;++i)
        cout<<a[i]<<" ";
    cout<<'\n';
    return 0;
}