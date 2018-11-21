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

ld angle(ll *a,ll *b,ll*c){
    ll num=(a[0]-b[0])*(c[0]-b[0])+(a[1]-b[1])*(c[1]-b[1])+(a[2]-b[2])*(c[2]-b[2])+(a[3]-b[3])*(c[3]-b[3])+(a[4]-b[4])*(c[4]-b[4]);
    ld den=sqrt((a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1])+(a[2]-b[2])*(a[2]-b[2])+(a[3]-b[3])*(a[3]-b[3])+(a[4]-b[4])*(a[4]-b[4]));
    ld den1=sqrt((c[0]-b[0])*(c[0]-b[0])+(c[1]-b[1])*(c[1]-b[1])+(c[2]-b[2])*(c[2]-b[2])+(c[3]-b[3])*(c[3]-b[3])+(c[4]-b[4])*(c[4]-b[4]));
    return num/den/den1;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl();
    ll a[n][5];
    for(int i=0;i<n;++i)
        for(int j=0;j<5;++j)
            a[i][j]=rl();
    if(n>11){
        cout<<"0\n";
        return 0;
    }
    vi ans;
    for(int i=0;i<n;){
        for(int j=0;j<n;++j){
            if(j==i)
                continue;
            for(int k=j+1;k<n;++k){
                if(k==i)
                    continue;
                if(angle(a[j],a[i],a[k])>0){
                    goto NEXT;
                }
            }
        }
        ans.push_back(i+1);
        NEXT:
            ++i;
    }
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();++i)
        cout<<ans[i]<<'\n';
    return 0;
}