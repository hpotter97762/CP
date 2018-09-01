#include<bits/stdc++.h>
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
//#define e 2.7182818284590452353602874713526624977572

typedef long long int ll;
typedef long double ld;
typedef std::vector<ll> vi;
typedef std::vector<bool> vb;
typedef std::vector<char> vc;
typedef std::pair<ll,ll> pii;
typedef std::vector<pii> vii;

using namespace std;
const ll mod=1e9+7,az=400010;

inline ll rl(){
    ll res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}

inline void read(string &s){
    s="";
    char c=getchar();
    while(c!='\n'&&c!=' '){
        s+=c;
        c=getchar();
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    vi fac(az),inv(az),facinv(az);
    fac[0]=facinv[0]=inv[1]=1;
    for(int i=1;i<az;++i)   fac[i]=fac[i-1]*i%mod;
    for(int i=2;i<az;++i)   inv[i]=((-mod/i*inv[mod%i])%mod+mod)%mod;
    for(int i=1;i<az;++i)   facinv[i]=facinv[i-1]*inv[i]%mod;
    string s;
    read(s);
    ll n=s.size(),c=0,b=0,ans=0;
    for(int i=0;i<n;++i)if(s[i]==')')++c;
    for(int i=0;i<n;++i){
        if(c<=0)
            break;
        if(s[i]==')'){
            --c;
            continue;
        }
        ++b;
        ans+=(fac[b+c-1]*facinv[b]%mod)*facinv[c-1]%mod;
        ans%=mod;
    }
    cout<<(ans+mod)%mod<<'\n';
    return 0;
}