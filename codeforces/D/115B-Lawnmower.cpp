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
const ll mod=1e9+7;

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed<<setprecision(25);
    ll n,m;
    cin>>n>>m;
    vector<string> a(n);
    for(ll i=0;i<n;++i)
        cin>>a[i];
    vii tp(n,{1e18,-1});
    ll nn=0;
    for(ll i=0;i<n;++i){
        for(ll j=0;j<m;++j){
            if(a[i][j]=='W'){
                tp[i]={min(tp[i].fs,j),max(tp[i].sc,j)};
            }
        }
        if(tp[i].sc!=-1)
            nn=i;
    }
    ll ans=0,curr=0;
    for(int i=0;i<=nn;++i){
        if(i%2){
            if(tp[i].sc!=-1){
                ans+=curr-tp[i].fs;
                curr=tp[i].fs;
            }
            if(i<nn&&tp[i+1].sc!=-1){
                ans+=max(curr-tp[i+1].fs,0LL);
                curr=min(curr,tp[i+1].fs);
            }
        }
        else{
            if(tp[i].sc!=-1){
                ans+=tp[i].sc-curr;
                curr=tp[i].sc;
            }
            if(i<nn&&tp[i+1].sc!=-1){
                ans+=max(tp[i+1].sc-curr,0LL);
                curr=max(curr,tp[i+1].sc);
            }
        }
        ++ans;
    }
    cout<<ans-1<<'\n';
    return 0;
}
