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

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n=rl(),sum=rl();
    if((n!=1&&sum==0)||(sum>n*9))
        cout<<-1<<' '<<-1<<'\n';
    else if(n==1&&sum==0)
        cout<<0<<' '<<0<<'\n';
    else{
        ll tmp=n,s=sum;
        while(n--){
            if(s==(n+1)*9){
                cout<<9;
                s-=9;
            }
            else{
                if(tmp==n+1){
                    cout<<max(1LL,s-n*9);
                    s-=max(1LL,s-n*9);
                }
                else{
                    cout<<max(0LL,s-n*9);
                    s-=max(0LL,s-n*9);
                }
            }
        }
        cout<<' ';
        s=sum,n=tmp;
        while(n--){
            if(s==0)
                cout<<0;
            else{
                cout<<min(9LL,s);
                s-=min(9LL,s);
            }
        }
    }
    cout<<'\n';
    return 0;
}