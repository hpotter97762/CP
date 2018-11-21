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
	ll h=rl()+1,n=0;
    vi a(h);
    for(int i=0;i<h;++i){
        a[i]=rl();
        n+=a[i];
    }
    ll i=0;
    for(i=0;i<h-1;++i){
        if(a[i]!=1&&a[i+1]!=1)
            break;
    }
    if(i==h-1){
        cout<<"perfect\n";
        return 0;
    }
    vi ans(n),ans1(n);
    ans[0]=ans1[0]=0;
    ll in=0,en=1;
    i=1;
    while((a[i-1]==1||a[i]==1)&&i<h){
        for(int j=en;j<en+a[i];++j){
            ans[j]=ans1[j]=in;
        }
        in=en;
        en=en+a[i];
        ++i;
    }
    for(int j=en;j<en+a[i];++j)
        ans[j]=in;
    ans1[en]=in;
    for(int j=en+1;j<en+a[i];++j)
        ans1[j]=in+1;
    in=en;
    en=en+a[i];
    ++i;
    for(;i<h;++i){
        for(int j=en;j<en+a[i];++j)
            ans[j]=ans1[j]=in;
        in=en;
        en=en+a[i];
    }
    cout<<"ambiguous\n";
    cout<<0<<' ';
    for(int i=1;i<n;++i)
        cout<<ans[i]+1<<' ';
    cout<<'\n';
    cout<<0<<' ';
    for(int i=1;i<n;++i)
        cout<<ans1[i]+1<<' ';
    cout<<'\n';
	return 0;
}