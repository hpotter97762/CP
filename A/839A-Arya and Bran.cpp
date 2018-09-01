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
#define e 2.7182818284590452353602874713526624977572
/*
#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#endif
*/
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
    int n=read_int(),k=read_int();
    int a[n];
    for(int i=0;i<n;++i)
        a[i]=read_int();
    int cnt=0,tot=0;
    for(int i=0;i<n;++i){
        cnt+=max(0,a[i]-8);
        tot+=min(8,a[i]);
        if(a[i]<8){
            tot+=min(cnt,8-a[i]);
            cnt-=min(8-a[i],cnt);
        }
        if(tot>=k){
            cout<<i+1<<'\n';
            break;
        }
    }
    if(tot<k)
        cout<<"-1\n";
    return 0;
}