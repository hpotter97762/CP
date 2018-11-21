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
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl(),m=rl();
    vii a(m);
    for(int i=0;i<m;++i)
        a[i].fs=rl(),a[i].sc=rl();
    if(m==0){
        if(n==1)
            cout<<"1\n";
        else
            cout<<"-1\n";
        return 0;
    }
    deque<ll>pos;
    sort(a.begin(),a.end());
    ll i=0;
    while(a[i].sc==1&&i<m)++i;
    int j=0;
    if(i==m)
        goto ad;
    if(i)
        j=a[i-1].fs;
    else
        j=1;
    for(;j<a[i].fs;++j)
        pos.push_back(j);
    ad:;
    for(;i<m;++i){
        int k=pos.size();
        for(int j=0;j<k;++j){
            if(ceil(a[i].fs*1.0/pos[j])!=a[i].sc){
                pos.erase(pos.begin()+j);
                --j,--k;
            }
        }
    }
    if(pos.size()==0){
        if(a.back().sc==1&&n<=a.back().fs)
            cout<<"1\n";
        else
            cout<<"-1\n";
    }
    else{
        ll i=1,k=ceil(n*1.0/pos[0]);
        for(;i<pos.size();++i){
            if(ceil(n*1.0/pos[i])!=k)
                break;
        }
        if(i==pos.size())
            cout<<k<<'\n';
        else
            cout<<"-1\n";
    }
    return 0;
}