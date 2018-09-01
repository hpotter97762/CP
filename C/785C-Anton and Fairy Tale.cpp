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

ll binS(ll st,ll en,ll num){
    while(st<en){
        ll mid=st+(en-st)/2;
        ll sum=(mid*(mid+1))/2;
        if(sum<num)
            st=mid+1;
        else
            en=mid;
    }
    return st;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl(),m=rl();
    if(n<=m){
        cout<<n<<'\n';
        return 0;
    }
    else{
        ll k=binS(0LL,2e9,n-m);
        cout<<m+k<<'\n';
    }
    return 0;
}