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
    int a[k];
    for(int i=0;i<k;++i)
        a[i]=read_int();
    int i;
    int cnt[3];
    cnt[0]=2*n,cnt[1]=n,cnt[2]=0;
    for(i=0;i<k;++i){
        if(a[i]%2){
            if(cnt[2])
                cnt[2]--;
            else if(cnt[1]>0){
                cnt[1]--,cnt[0]++;
            }
            else
                cnt[0]--;
        }
        if(a[i]%4>=2){
            if(cnt[1]<=0||cnt[0]>0)
                cnt[0]--;
            else
                cnt[1]--,cnt[2]++;
        }
        cnt[1]-=a[i]/4;
        if(cnt[1]<0){
            cnt[0]+=cnt[1]*2;
            cnt[1]=0;
        }
        if(cnt[0]<0){
            cnt[2]+=2*cnt[0];
            cnt[0]=0;
        }
        if(cnt[0]<0||cnt[1]<0||cnt[2]<0)
            break;
    }
    if(i==k)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}