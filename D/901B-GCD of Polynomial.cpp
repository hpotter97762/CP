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
    char c=getchar();
    while(c!='\n'){
        s+=c;
        c=getchar();
    }
}

void add(vi &c,vi &a,vi &b,int p){
    int i;
    for(i=0;i<a.size();++i)
        c[i]=a[i]*p+b[i];
    for(;i<b.size();++i)
        c[i]=b[i];
}

bool check(vi &c)
{
    for(int i=0;i<c.size();++i)
        if(c[i]==2||c[i]==-2)
            return true;
    return false;
}

void print(vi &a){
    cout<<a.size()-1<<'\n';
    for(int i=0;i<a.size();++i)
        cout<<a[i]<<' ';
    cout<<'\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl();
    vi a(1),b(2),c;
    a[0]=b[1]=1,b[0]=0;
    --n;
    while(n--){
        vi tp=b;
        b.insert(b.begin(),0);
        c.resize(b.size());
        add(c,a,b,1);
        if(check(c))
            add(c,a,b,-1);
        a=tp;
        b=c;
    }
    print(b);
    print(a);
    return 0;
}