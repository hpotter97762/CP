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
const ll mod=1e9+7,phimod=1e9+6;

inline int ri(){
    int res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}

inline ll rl(){
    ll res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl(),k=rl();
    ll f2=0,f5=0;
    ll p=n;
    while(n%2==0){
        f2++;
        n/=2;
    }
    while(n%5==0){
        f5++;
        n/=5;
    }
    if(f2<f5){
        while(f2!=f5&&f2<k){
            p*=2;
            f2++;
        }
    }
    else{
        while(f2!=f5&&f5<k){
            p*=5;
            f5++;
        }
    }
    while(min(f2,f5)<k){
        p*=10;
        f2++,f5++;
    }
    cout<<p<<'\n';
    return 0;
}