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
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll a=rl(),b=rl(),f=rl(),k=rl();
    if(a-f>b||f>b){
        cout<<"-1\n";
        return 0;
    }
    ll ans=0,left=b;
    for(int i=0;i<k;++i){
        if(i%2){
            left-=a-f;
            if(left<0){
                cout<<"-1\n";
                return 0;
            }
            if((i!=k-1&&2*f>left)||(i==k-1&&f>left))
                ans++,left=b;
            left-=f;
        }
        else{
            left-=f;
            if(left<0){
                cout<<"-1\n";
                return 0;
            }
            if((i!=k-1&&2*(a-f)>left)||(i==k-1&&a-f>left))
                ans++,left=b;
            left-=(a-f);
        }
    }
    cout<<ans<<'\n';
    return 0;
}