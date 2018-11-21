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
const ll mod=1e9+7;

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
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl(),p=rl(),q=rl(),r=rl();
    vi a(n);
    vi lmin(n),rmin(n),lmax(n),rmax(n);
    for(int i=0;i<n;++i)
        a[i]=rl();
    lmin[0]=lmax[0]=a[0],rmin[n-1]=rmax[n-1]=a[n-1];
    for(int i=1;i<n;++i){
        lmin[i]=min(lmin[i-1],a[i]);
        lmax[i]=max(lmax[i-1],a[i]);
    }
    for(int i=n-2;i>=0;--i){
        rmin[i]=min(rmin[i+1],a[i]);
        rmax[i]=max(rmax[i+1],a[i]);
    }
    ll ans=-4*1e18,tpl,tpr;
    for(int j=0;j<n;++j){
        if(p<0)
            tpl=lmin[j];
        else
            tpl=lmax[j];
        if(r>0)
            tpr=rmax[j];
        else
            tpr=rmin[j];
        ans=max(ans,p*tpl+q*a[j]+r*tpr);
    }
    cout<<ans<<'\n';
    return 0;
}