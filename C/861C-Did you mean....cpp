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
    string s;
    getline(cin,s);
    ll cnt=0,f=1;
    for(int i=0;i<s.size();++i){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]==' ')
            cnt=0,f=1;
        else
            cnt++;
        if(cnt>1){
            if(s[i]!=s[i-1])
                f++;
        }
        if(cnt>=3&&f>1)
            cout<<' ',f=1,cnt=1;
        cout<<s[i];
    }
    return 0;
}