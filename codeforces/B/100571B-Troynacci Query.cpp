#include<bits/stdc++.h>
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
#define e 2.7182818284590452353602874713526624977572

typedef long long int ll;
typedef long double ld;
typedef std::vector<ll> vi;
typedef std::vector<bool> vb;
typedef std::vector<char> vc;
typedef std::pair<ll,ll> pii;
typedef std::vector<pii> vii;

using namespace std;
const int mod=1e9+7;

inline ll rl(){
    ll res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}

inline void read(string &s){
    char c=getchar();
    while(c!='\n'){s+=c;c=getchar();}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n=rl(),q=rl();
    vi f(n);
    f[0]=rl(),f[1]=rl();
    ll a=rl(),b=rl();
    for(int i=2;i<n;++i)
        f[i]=(a*f[i-2]%mod+b*f[i-1]%mod)%mod;
    vi x(n);
    for(int i=0;i<n;++i)
        x[i]=rl();
    vi p(n+3,0);
    while(q--){
        ll l=rl()-1,r=rl()-1;
        p[l]=(p[l]+f[0])%mod;
        if(l!=r){
            p[l+1]=(p[l+1]+f[1])%mod;
            if(l)
                p[l+1]=(p[l+1]-f[0]*b%mod+mod)%mod;
            //cout<<p[r+1]<<' '<<f[r-l]*b<<' '<<f[r-l-1]*a<<'\n';
            p[r+1]=(p[r+1]-f[r-l]*b%mod+2*mod-f[r-l-1]*a%mod)%mod;
            //cout<<p[r+1]<<' '<<f[r-l]*b<<' '<<f[r-l-1]*a<<'\n';
            p[r+2]=(p[r+2]-f[r-l]*a%mod+mod)%mod;
        }
        else{
            if(r)
                p[r+1]=(p[r+1]-f[0]*b%mod+mod)%mod;
            p[r+2]=(p[r+2]-f[0]*a%mod+mod)%mod;
        }
    }/*
    for(int i=0;i<n;++i)
        cout<<p[i]<<' ';
    cout<<'\n';
    for(int i=0;i<n;++i)
        cout<<f[i]<<' ';
    cout<<'\n';*/
    for(int i=0;i<n;++i){
        x[i]+=p[i];
        if(i>1)
            x[i]=(x[i]+p[i-1]*b%mod+p[i-2]*a%mod+mod)%mod,p[i]=(p[i]+p[i-1]*b%mod+p[i-2]*a%mod)%mod;
        cout<<x[i]%mod<<' ';
    }
    cout<<'\n';
	return 0;
}