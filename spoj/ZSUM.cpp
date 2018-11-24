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
 
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
 
using namespace std;
const int mod=1e7+7;
 
inline int ri(){
    int res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){
        res=(res<<1)+(res<<3)+c-48;
        c=getchar();
    }
    return neg?-res:res;
}
 
inline ll rl(){
    ll res=0;
    int neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){
        res=(res<<1)+(res<<3)+c-48;
        c=getchar();
    }
    return neg?-res:res;
}
 
ll modexp(ll a,ll b){
    ll ans=1;
    while(b>0){
        if(b%2){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
 
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl(),k=rl();
    while(n){
        cout<<(modexp(n,n)+2*modexp(n-1,n-1)+modexp(n,k)+2*modexp(n-1,k))%mod<<'\n';
        n=rl(),k=rl();
    }
    return 0;
}
 
 
