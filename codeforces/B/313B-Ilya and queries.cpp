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
    string a;
    read(a);
    ll n=a.size(),m=rl();
    vi an(n);
    an[0]=(a[0]==a[1]);
    for(int i=1;i<n-1;++i)
        an[i]+=(a[i]==a[i+1])+an[i-1];
    an[n-1]=a[n-2];
    while(m--){
        ll l=rl()-2,r=rl()-2;
        if(l>=0)
            cout<<an[r]-an[l]<<'\n';
        else
            cout<<an[r]<<'\n';
    }
    return 0;
}