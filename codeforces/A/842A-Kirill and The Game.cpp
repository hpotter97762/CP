#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define mp make_pair
#define pii pair<ll,ll>
#define vii vector<pair<ll,ll> >
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
//#define e 2.7182818284590452353602874713526624977572

using namespace std;
const int mod=1000000007;

int read_int(){
    int res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){
        res=(res<<1)+(res<<3)+c-48;
        c=getchar();
    }
    return neg?-res:res;
}

ll read_ll(){
    ll res=0;
    int neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){
        res=(res<<1)+(res<<3)+c-48;
        c=getchar();
    }
    return neg?-res:res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll l,r,x,y;
    ld k;
    cin>>l>>r>>x>>y>>k;
    int i;
    for(i=l;i<=r;++i){
        if(ceil(i/k)==floor(i/k)&&i/k>=x&&i/k<=y)
            break;
    }
    if(i==r+1)
        cout<<"NO\n";
    else
        cout<<"YES\n";
    return 0;
}
