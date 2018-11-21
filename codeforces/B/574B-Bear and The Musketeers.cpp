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
vector<map<ll,bool> > adj;

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,q,r;
    cin>>n>>m;
    adj.resize(n);
    for(int i=0;i<m;++i){
        cin>>q>>r;
        --q,--r;
        adj[q][r]=adj[r][q]=1;
    }
    ll ans=1e18;
    for(int i=0;i<n;++i){
        for(auto j:adj[i]){
            for(auto k:adj[j.fs]){
                if(adj[k.fs].find(i)!=adj[k.fs].end()){
                    ans=min(ans,(ll)(adj[i].size()+adj[j.fs].size()+adj[k.fs].size()));
                }
            }
        }
    }
    cout<<(ans==1e18?-1:(ans-6))<<'\n';
    return 0;
}