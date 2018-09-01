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

ll calc(vi &a,ll key){
    ll beg=0,las=a.size()-1;
    while(beg<=las){
        ll mid=(beg+las)/2;
        if(a[mid]>key)
            las=mid-1;
        else if(a[mid]<key)
            beg=mid+1;
        else
            return 0;
    }
    if(las<0)
        return a[beg]-key;
    if(beg>=a.size())
        return key-a[las];
    return min(key-a[las],a[beg]-key);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl(),m=rl(),q=rl();
    ll a[n],b[m];
    for(int i=0;i<n;++i)
        a[i]=rl();
    for(int i=0;i<m;++i)
        b[i]=rl();
    ll i=0,s=0,p=0;
    for(i=0;i<n;++i){
        if(i%2)
            p-=a[i],s-=b[i];
        else
            p+=a[i],s+=b[i];
    }
    vi bsum;
    bsum.push_back(s);
    ll k;
    if(n%2)k=1;else k=-1;
    for(;i<m;++i){
        s-=(k*b[i]+b[i-n]);
        s=-s;
        bsum.push_back(s);
    }
    sort(bsum.begin(),bsum.end());
    ll l,r,x,tmp=0;
    cout<<calc(bsum,p)<<'\n';
    while(q--){
        l=rl(),r=rl(),x=rl();
        --l,--r;
        if((r-l)%2)
            tmp=0;
        else if(l%2)
            tmp=-x;
        else
            tmp=x;
        p+=tmp;
        cout<<calc(bsum,p)<<'\n';
    }
    return 0;
}