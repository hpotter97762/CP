#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<ll,ll>
#define vii vector<pair<ll,ll> >
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
//#define e 2.7182818284590452353602874713526624977572


using namespace std;
const ll mod=1e9+7,phimod=1e9+6;

inline int ri(){
    int res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}

inline ll rl(){
    ll res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n=rl(),a;
    vii cnt(101,{0,0});
    for(int i=0;i<n;++i){
        a=rl();
        cnt[a].fs++;
        cnt[a].sc=a;
    }
    sort(cnt.begin(),cnt.end());
    ll i;
    for(i=1;i<101;++i){
        if(cnt[i].fs==cnt[i-1].fs&&cnt[i].fs!=0)
            break;
    }
    if(i==101)
        cout<<"NO\n";
    else{
        if(cnt[i].fs*2==n)
            cout<<"YES\n"<<cnt[i].sc<<" "<<cnt[i-1].sc;
        else
            cout<<"NO\n";
    }
    return 0;
}