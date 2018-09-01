#include<bits/stdc++.h>
#define ll long long int
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
    vi pow(51);
    pow[0]=1;
    for(int i=1;i<51;++i){
        pow[i]=pow[i-1]*2;
    }
    ll n=read_ll(),m=read_ll();
    vector<vb>a(n,vb(m));
    char c;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            c=getchar();
            a[i][j]=(c=='1');
            c=getchar();
        }
    }
    ll ans=0;
    for(int i=0;i<n;++i){
        ll cnt=0;
        for(int j=0;j<m;++j){
            cnt+=a[i][j];
        }
        ans+=(pow[cnt]-1)+(pow[m-cnt]-1);
    }
    for(int i=0;i<m;++i){
        int cnt=0;
        for(int j=0;j<n;++j){
            cnt+=a[j][i];
        }
        ans+=(pow[cnt]-1)+(pow[n-cnt]-1)-n;
    }
    cout<<max(1LL,ans)<<'\n';
    return 0;
}
