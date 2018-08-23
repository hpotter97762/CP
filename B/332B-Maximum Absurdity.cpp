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
    ll n,k;
    cin>>n>>k;
    vi a(n);
    cin>>a[0];
    for(int i=1;i<n;++i){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    if(k==0){
        cout<<1<<' '<<1<<'\n';
        return 0;
    }
    vi preAns(n,-1),preAnsInd(n,-1);
    preAns[k-1]=a[k-1];
    preAnsInd[k-1]=0;
    for(int i=k;i<n;++i){
        if(preAns[i-1]>=a[i]-a[i-k]){
            preAns[i]=preAns[i-1];
            preAnsInd[i]=preAnsInd[i-1];
        }
        else{
            preAns[i]=a[i]-a[i-k];
            preAnsInd[i]=i-k;
        }
    }
    vi postAns(n,-1),postAnsInd(n);
    postAns[n-k]=a[n-1]-a[n-k-1];
    postAnsInd[n-k]=n-k;
    for(int i=n-k-1;i>0;--i){
        if(postAns[i+1]>a[i+k-1]-a[i-1]){
            postAns[i]=postAns[i+1];
            postAnsInd[i]=postAnsInd[i+1];
        }
        else{
            postAns[i]=a[i+k-1]-a[i-1];
            postAnsInd[i]=i;
        }
    }
    if(postAns[1]>a[k-1]){
        postAns[0]=postAns[1];
        postAnsInd[0]=postAnsInd[1];
    }
    else{
        postAns[0]=a[k-1];
        postAnsInd[0]=0;
    }
    ll ans=0,ind1=-1,ind2=-1;
    for(ll i=0;i<=n-k;++i){
        ll tmp=-1,pre=-1;
        if(i>=k){
            tmp=preAnsInd[i-1];
            pre=preAns[i-1];
        }
        if(i<n-k){
            if(pre<postAns[i+k]){
                tmp=postAnsInd[i+k];
                pre=postAns[i+k];
            }
        }
        if(ans<pre+a[i+k-1]-(i>0?a[i-1]:0)||(ans==pre&&min(i,tmp)<ind1)){
            ind1=min(i,tmp),ind2=max(i,tmp);
            ans=pre+a[i+k-1]-(i>0?a[i-1]:0);
        }
        // cout<<ind1+1<<' '<<ind2+1<<' '<<ans<<'\n';
    }
    cout<<ind1+1<<' '<<ind2+1<<'\n';
    return 0;
}