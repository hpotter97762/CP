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
vi st,a;
 
ll build(ll s,ll e,ll i){
    if(s==e)
        return st[i]=a[s];
    return st[i]=min(build(s,(s+e)/2,2*i+1),build((s+e)/2+1,e,2*i+2));
}
 
ll query(ll l,ll r,ll s,ll e,ll i){
    if(l>r||s>e)
        return 1e9;
    if(s==l&&r==e)
        return st[i];
    ll mid=(s+e)/2;
    if(r<=mid)
        return query(l,r,s,mid,2*i+1);
    if(l>mid)
        return query(l,r,mid+1,e,2*i+2);
    return min(query(mid+1,r,mid+1,e,2*i+2),query(l,mid,s,mid,2*i+1));
}
 
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	ll n=rl();
	a.resize(n);
	for(int i=0;i<n;++i)
        a[i]=rl();
    st.resize(4*n);
    st[0]=build(0,n-1,0);
    ll q=rl();
    while(q--){
        ll l=rl(),r=rl();
        cout<<query(l,r,0,n-1,0)<<'\n';
    }
	return 0;
}
