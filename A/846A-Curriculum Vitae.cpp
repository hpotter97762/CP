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
    while(c>='0'&&c<='9'){
        res=(res<<1)+(res<<3)+c-48;
        c=getchar();
    }
    return neg?-res:res;
}

inline ll rl(){
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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n=ri();
    bool a[n];
    char c;
    for(int i=0;i<n;++i){
        c=getchar();
        a[i]=(c=='1');
        c=getchar();
    }
    ll c0=0,c1=0;
    vi cnt;
    if(n==1)
        cnt.push_back(1);
    for(int i=1;i<n;++i){
        ll ct=1;
        while(a[i]==a[i-1]&&i<n)++i,++ct;
        cnt.push_back(ct);
    }
    if(a[n-1]!=a[n-2]&&n!=1)
        cnt.push_back(1);
    ll i=0,in=0,mx=0;
    if(!a[0]){
        i=1,in=1;
    }
    ll ind=in,mxp=0;
    for(;i<cnt.size();++i){
        if((i-in)%2)
            c0+=cnt[i];
        else
            c1+=cnt[i];
        if(mxp<(c0-c1)){
            mxp=c0-c1;
            mx=c0;
            ind=i;
        }
    }
    if(!a[0])
        mx+=cnt[0];
    for(int j=ind;j<cnt.size();++j){
        if((j-in)%2==0)
            mx+=cnt[j];
    }
    cout<<mx<<'\n';
    return 0;

}