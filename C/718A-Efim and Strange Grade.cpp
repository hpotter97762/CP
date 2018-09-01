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
    ll n=rl(),t=rl();
    string s;
    read(s);
    ll i,flag=0;
    for(i=0;i<n;++i){
        if(s[i]=='.')
            flag=1;
        else if(flag&&s[i]>='5')
            break;
    }
    if(i==n){
        cout<<s<<'\n';
        return 0;
    }
    while(t--&&s[i]>='5'){
        if(s[i-1]!='.')
            --i,s[i]++,s[i+1]=0;
        else{
            i-=2,s[i]++,s[i+1]=0;
            break;
        }
    }
    while(!isdigit(s[i])){
        s[i]='0';
        --i;
        if(i<0){
            cout<<'1';
            break;
        }
        s[i]++;
    }
    i=-1;
    while(s[++i]!=0)
        cout<<s[i];
    cout<<'\n';
    return 0;
}