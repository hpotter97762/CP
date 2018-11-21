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
const ld con=0.0000000001;

void shortcut(ld a,ll b,ld &c,ld &d,ll e,ll f,ll g){
    if(a*b+e>=f&&a*b+e<=g){
        if(c!=a&&d!=a){
            if(c==1e18)
                c=a;
            else
                d=a;
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1>x2){
        ll tp=x1;
        x1=x2;
        x2=tp;
    }
    if(y1>y2){
        ll tp=y1;
        y1=y2;
        y2=tp;
    }
    ll x,y,vx,vy;
    ld mn=-1e18,mx=1e18;
    for(int i=0;i<n;++i){
        cin>>x>>y>>vx>>vy;
        ld tpx1,tpx2,tpy1,tpy2;
        if(vx==0){
            if(x<=x1||x>=x2){
                cout<<-1<<'\n';
                return 0;
            }
            else{
                tpx1=-1e18;
                tpx2=1e18;
            }
        }
        else{
            tpx1=(x1-x)/1.0/vx;
            tpx2=(x2-x)/1.0/vx;
        }
        if(vy==0){
            if(y<=y1||y>=y2){
                cout<<-1<<'\n';
                return 0;
            }
            else{
                tpy1=-1e18;
                tpy2=1e18;
            }
        }
        else{
            tpy1=(y1-y)/1.0/vy;
            tpy2=(y2-y)/1.0/vy;
        }
        ld tmp1=1e18,tmp2=1e18;
        shortcut(tpx1,vy,tmp1,tmp2,y,y1,y2);
        shortcut(tpx2,vy,tmp1,tmp2,y,y1,y2);
        shortcut(tpy1,vx,tmp1,tmp2,x,x1,x2);
        shortcut(tpy2,vx,tmp1,tmp2,x,x1,x2);
        if(tmp1==1e18||tmp2==1e18){
            tmp1=tmp2=min(tmp1,tmp2);
        }
        if(vx==0&&vy==0&&x>x1&&x<x2&&y>y1&&y<y2){
            tmp1=-1e18;
            tmp2=1e18;
        }
        mn=max(min(tmp1,tmp2),mn);
        mx=min(max(tmp1,tmp2),mx);
    }
    // cout<<mn<<' '<<mx<<'\n';
    if(mx>mn&&mn!=1e18){
        if(mx>=con)
            cout<<setprecision(20)<<max(mn,(ld)0);
        else
            cout<<-1<<'\n';
    }
    else
        cout<<-1<<'\n';
    return 0;
}