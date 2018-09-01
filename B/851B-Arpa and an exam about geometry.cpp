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
#define exp 2.7182818284590452353602874713526624977572

using namespace std;
const int mod=1000000007;

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

ll dist(ll *a,ll *b){
    return ((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]));
}

bool check(ll *a ,ll *b,ll *c){
    return (a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1]))!=0;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll a[2],b[2],c[2];
    cin>>a[0]>>a[1]>>b[0]>>b[1]>>c[0]>>c[1];
    if(dist(a,b)==dist(b,c)&&check(a,b,c))
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}