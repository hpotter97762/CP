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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n=rl(),m=rl(),k=rl();
	vi a(n);
	vb v(n,0);
	for(int i=0;i<n;++i)
        a[i]=rl();
    if(k==1){
        cout<<n<<'\n';
        return 0;
    }
    sort(a.begin(),a.end());
    int j=0,cnt=0,num=0;
    for(int i=0;j<n&&i<n;++i){
        if(v[i])continue;
        while(a[j]-a[i]<m&&j<n){
            if(!v[j])
            ++num;
            if(num>=k)v[j]=1;
            ++j;
        }
        if(num>=k)
            cnt+=num-k+1,num=k-1;
        --num;
    }
    cout<<cnt<<'\n';
	return 0;
}