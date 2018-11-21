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

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl();
    vii a(n);
    for(int i=0;i<n;++i)
        a[i].fs=rl(),a[i].sc=getchar(),getchar();
    ll ans=0;
    sort(a.begin(),a.end());
    ll st=n;
    vi nx(n);
    for(int i=n-1;i>=0;--i){
        nx[i]=st;
        if(a[i].sc=='G')
            st=i;
    }
    ll p=-1;
    for(int i=st;p<n;i=nx[i]){
        ll r=0,b=0,pr=p,pb=p,anb=0,anr=0,totb=0,totr=0;
        for(int j=p+1;j<i;++j){
            if(a[j].sc=='R'){
                ++r;
                if(pr==p){
                    if(p>=0)
                        anr=a[j].fs-a[p].fs,totr+=a[j].fs-a[p].fs;
                    else
                        anr=0;
                }
                else
                    anr=max(anr,a[j].fs-a[pr].fs),totr+=a[j].fs-a[pr].fs;
                pr=j;
            }
            if(a[j].sc=='B'){
                ++b;
                if(pb==p){
                    if(p>=0)
                        anb=a[j].fs-a[p].fs,totb+=a[j].fs-a[p].fs;
                    else
                        anb=0;
                }
                else
                    anb=max(anb,a[j].fs-a[pb].fs),totb+=a[j].fs-a[pb].fs;
                pb=j;
            }
        }
        if(pr!=-1&&i!=n)
            totr+=a[i].fs-a[pr].fs,anr=max(anr,a[i].fs-a[pr].fs);
        if(pb!=-1&&i!=n)
            totb+=a[i].fs-a[pb].fs,anb=max(anb,a[i].fs-a[pb].fs);
        ll tmp=totb+totr;
        if(i!=n&&p!=-1){
            tmp=min(tmp,tmp-anb-anr+a[i].fs-a[p].fs);
        }
        ans+=tmp;
        p=i;
    }
    cout<<ans<<'\n';
    return 0;
}