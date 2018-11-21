#include<bits/stdc++.h>
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
#define e 2.7182818284590452353602874713526624977572

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

bool f(ll x,ll y,ld m,ld c){
    if(y-m*x-c==0)
        return true;
    return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    ll n=rl();
    vi a(n);
    for(ll i=0;i<n;++i)
        a[i]=rl();
    vb val(n);
    for(ll i=1;i<n;++i){
        ld k=(a[i]-a[0])*1.0/i,c;
        c=a[i]-k*i;
        fill(val.begin(),val.end(),false);
        for(ll j=0;j<n;++j){
            val[j]=f(j,a[j],k,c);
        }
        int j;
        for(j=0;j<n;++j){
            if(val[j]==0){
                break;
            }
        }
        if(j==n){
            cout<<"No\n";
            return 0;
        }
        c=a[j]-k*j;
        for(int j=0;j<n;++j){
            val[j]=val[j]|f(j,a[j],k,c);
        }
        for(j=0;j<n;++j)
            if(!val[j])break;
        if(j==n){
            cout<<"Yes\n";
            return 0;
        }
    }
    ld k=(a[2]-a[1]),c;
    c=a[1]-k;
    int i;
    for(i=1;i<n;++i){
        if(!f(i,a[i],k,c))
            break;
    }
    if(i==n)
        cout<<"Yes\n";
    else
        cout<<"No\n";
	return 0;
}