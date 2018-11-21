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
    ll n=rl(),l=rl();
    vi a(n);
    for(int i=0;i<n;++i)
        a[i]=rl();
    ll prev=0;
    sort(a.begin(),a.end());
    ld ans=a[0];
    for(int i=0;i<n;++i){
        ans=max(ans,(ld)(a[i]-prev)/2);
        prev=a[i];
    }
    cout<<setprecision(15)<<max(ans,(ld)(l-a[n-1]));
    return 0;
}