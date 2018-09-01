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
ll n;
vc a;

void print(vi &a){
    for(int i=0;i<a.size();++i)
        cout<<a[i]<<' ';
    cout<<'\n';
}

ll call(){
    vector<vi> dp(n,vi(n,0));
    dp[0][0]=1;
    for(int i=1;i<n;++i){
        for(int j=0;j<n;++j){
            if(a[i-1]=='s')
                dp[i][j]=dp[i-1][j];
            else{
                if(j==0)
                    dp[i][j]=0;
                else
                    dp[i][j]=(dp[i-1][j-1]-dp[i-1][j]+mod)%mod;
            }
        }
        //print(dp[i]);
        for(int j=n-2;j>=0;--j)
            dp[i][j]=(dp[i][j]+dp[i][j+1])%mod;
        //print(dp[i]);
    }
    return dp[n-1][0];
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    n=rl();
    a.resize(n);
    for(int i=0;i<n;++i){
        a[i]=getchar();
        getchar();
    }
    cout<<call()<<'\n';
    return 0;
}