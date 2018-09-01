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
    s="";
    char c=getchar();
    while(c!='\n'&&c!=' '){
        s+=c;
        c=getchar();
    }
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll u=rl(),v=rl(),w=rl(),x=rl();
	ll a1,a2,a3;
	a3=max(x,w);
	if(a3>x*2||a3>w*2)
        a3=-1;
	a2=max(2*x+1,max(a3+1,v));
	if(a2>2*v)
        a2=-1;
	a1=max(x*2+1,max(a2+1,u));
	if(a1>2*u)
        a1=-1;
    if(a1!=-1&&a2!=-1&&a3!=-1)
        cout<<a1<<'\n'<<a2<<'\n'<<a3<<'\n';
    else
        cout<<-1<<'\n';
	return 0;
}