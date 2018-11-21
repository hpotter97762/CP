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
    ll n=rl(),w=rl(),h=rl(),z=100000,ymin=1e5,xmin=1e5,ymax=1e5,xmax=1e5;
    vector<vii> x(200001),y(200001);
    vi init(n);
    for(int i=0;i<n;++i){
        ll g=rl(),p=rl(),t=rl();
        init[i]=p;
        if(g==1)
            x[p+z-t].push_back({p,i}),xmin=min(xmin,p+z-t),xmax=max(xmax,p+z-t);
        else
            y[p+z-t].push_back({p,i}),ymin=min(ymin,p+z-t),ymax=max(ymax,p+z-t);
    }
    for(int i=xmin;i<=xmax;++i)
        sort(x[i].begin(),x[i].end());
    for(int i=ymin;i<=ymax;++i)
        sort(y[i].begin(),y[i].end());
    vii ans(n);
    for(int i=min(ymin,xmin);i<=max(ymax,xmax);++i){
        if(y[i].empty()){
            if(!x[i].empty()){
                for(int j=0;j<x[i].size();++j){
                    ans[x[i][j].sc]={init[x[i][j].sc],h};
                }
            }
        }
        else{
            for(int j=0;j<x[i].size();++j){
                ll rt=x[i].size()-j-1;
                if(rt>=y[i].size()){
                    ans[x[i][j].sc]={init[x[i][j+y[i].size()].sc],h};
                }
                else{
                    ans[x[i][j].sc]={w,init[y[i][rt].sc]};
                }
            }
            for(int j=0;j<y[i].size();++j){
                ll tp=y[i].size()-j-1;
                if(tp>=x[i].size()){
                    ans[y[i][j].sc]={w,init[y[i][j+x[i].size()].sc]};
                }
                else{
                    ans[y[i][j].sc]={init[x[i][tp].sc],h};
                }
            }
        }
    }
    for(int i=0;i<n;++i){
        cout<<ans[i].fs<<" "<<ans[i].sc<<'\n';
    }
	return 0;
}