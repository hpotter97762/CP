 By hpotter97762, contest: Codeforces Round #422 (Div. 2), problem: (C) Hacker, pack your bags!, Accepted, #

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

inline void read(vi &a){
    for(int i=0;i<a.size();++i)
        a[i]=rl();
}

struct voucher{
    ll l,r,cost;
};

bool cmp(voucher a,voucher b){
    if(a.r-a.l==b.r-b.l){
        return a.l<b.l;
    }
    return a.r-a.l<b.r-b.l;
}

ll bins(int st,int en,vector<voucher> &a,ll k){
    while(st<en){
        ll mid=(st+en)/2;
        if(a[mid].l<=k)
            st=mid+1;
        else
            en=mid;
    }
    if(a[en].l>k)
        return en;
    return en+1;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n=rl(),x=rl();
    vector<voucher> a(n);
    for(int i=0;i<n;++i)
        a[i]={rl(),rl(),rl()};
    sort(a.begin(),a.end(),cmp);
    ll i=0,j=n-1,ans=1e18,flag=0,ind;
    vi mn(n);
    mn[n-1]=a[n-1].cost;
    for(ll i=n-2;i>=0;--i){
        if(a[i+1].r-a[i+1].l==a[i].r-a[i].l)
            mn[i]=min(mn[i+1],a[i].cost);
        else
            mn[i]=a[i].cost;
    }
    vii dur(2e5+2,{1e18,-1});
    for(ll i=0;i<n;++i){
        ll tp=a[i].r-a[i].l+1;
        dur[tp].fs=min(i,dur[tp].fs);
        dur[tp].sc=max(dur[tp].sc,i);
    }
    for(int i=0;i<n;++i){
        ll tp=a[i].r-a[i].l+1;
        if(x-tp>=0&&dur[x-tp].fs!=1e18){
            ll tmp=bins(dur[x-tp].fs,dur[x-tp].sc,a,a[i].r);
            if(tmp<=dur[x-tp].sc){
                ans=min(ans,a[i].cost+mn[tmp]);
            }
        }
    }
    if(ans==1e18)
        cout<<-1<<'\n';
    else
        cout<<ans<<'\n';
    return 0;
}