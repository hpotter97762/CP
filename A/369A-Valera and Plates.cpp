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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl(),m=rl(),ans=0,k=rl(),b=0,p=0,a;
    for(int i=0;i<n;++i){
    	a=rl();
    	if(a==1){
    		if(b==m)
    			++ans;
    		else
    			++b;
    	}
    	if(a==2){
    		if(p!=k)
    			++p;
    		else if(b!=m)
    			++b;
    		else
    			ans++;
    	}
    }
    cout<<ans<<'\n';
	return 0;
}