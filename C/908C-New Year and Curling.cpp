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
    ll n=rl(),r=rl();
    vi x(n);
    for(int i=0;i<n;++i)
        x[i]=rl();
    vector<ld> y(n);
    y[0]=r;
    for(int i=1;i<n;++i){
        int j;
        y[i]=r;
        for(j=i-1;j>=0;--j){
            if(abs(x[i]-x[j])<=2*r){
                ld tmp=sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j]));
                if(tmp>=0)
                    y[i]=max(y[j]+tmp,y[i]);
                else
                    y[i]=max(y[i],y[j]-tmp);
            }
        }
    }
    for(int i=0;i<n;++i)
        cout<<setprecision(15)<<y[i]<<' ';
    cout<<'\n';
    return 0;
}