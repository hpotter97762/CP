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
const ll mod=1e9+7;

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

inline void read(vi &a){
    for(int i=0;i<a.size();++i)
        a[i]=rl();
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n=rl();
    vi b(n);
    read(b);
    ll i=1,j=n-2;
    sort(b.begin(),b.end());
    while(i<n&&b[i]==b[i-1])++i;
    while(j>=0&&b[j]==b[j+1])--j;
    cout<<(b[n-1]-b[0])<<' ';
    if(i!=n)
        cout<<(n-j-1)*i<<'\n';
    else
        cout<<n*(n-1)/2<<'\n';
    return 0;
}