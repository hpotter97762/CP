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

void print(vi &a){
    for(int i=0;i<a.size();++i)
        cout<<a[i]<<' ';
    cout<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n=rl();
    vi a(n),b(n-2),c(n-1);
    for(int i=0;i<n;++i)
        a[i]=rl();
    for(int i=0;i<n-1;++i)
        c[i]=rl();
    for(int i=0;i<n-2;++i)
        b[i]=rl();
    b.push_back(1e18),c.push_back(2e18);
    sort(b.begin(),b.end());
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    int i,j,k=0;
    for(i=0,j=0;i<n;++j,++i){
        if(a[i]!=c[j]){
            cout<<a[i]<<'\n';
            break;
        }
    }
    for(i=0,j=0;i<n-1;++j,++i){
        if(b[j]!=c[i]){
            cout<<c[i]<<'\n';
            break;
        }
    }
    return 0;
}