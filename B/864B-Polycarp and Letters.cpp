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
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vi cpt;
    for(int j=0;j<n;++j){
        if(isupper(s[j]))
            cpt.push_back(j);
    }
    ll st,en=-1;
    ll i=0,mx=0;
    while(i<cpt.size()){
        st=en+1;
        en=cpt[i++];
        vi is(26,0);
        for(;st<en;++st){
            is[s[st]-'a']=1;
        }
        ll ct=0;
        for(int j=0;j<26;++j)
            ct+=is[j];
        mx=max(mx,ct);
    }
    st=en+1;
    en=n;
    vi is(26,0);
    for(;st<en;++st){
        is[s[st]-'a']=1;
    }
    ll ct=0;
    for(int j=0;j<26;++j)
        ct+=is[j];
    mx=max(mx,ct);
    cout<<mx<<'\n';
    return 0;
}