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
    ll n;
    cin>>n;
    vi a(n),hash(n+1),alreadyThere,notThere;
    for(int i=0;i<n;++i){
        cin>>a[i];
        if(a[i]>n||a[i]<1||hash[a[i]]==1){
            alreadyThere.push_back(a[i]);
        }
        if(a[i]<=n&&a[i]>0)
            hash[a[i]]=1;
    }
    for(int i=1;i<=n;++i){
        if(hash[i]==0){
            notThere.push_back(i);
        }
    }
    ll ans=0;
    sort(alreadyThere.begin(),alreadyThere.end());
    sort(notThere.begin(),notThere.end());
    for(int i=0;i<notThere.size();++i){
        // cout<<alreadyThere[i]<< ' '<<notThere[i]<<'\n';
        ans+=(abs(notThere[i]-alreadyThere[i]));
    }
    cout<<ans<<'\n';
    return 0;
}