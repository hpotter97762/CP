#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
    int operator()(int x) const { return (x ^ RANDOM); }
};
gp_hash_table<ll,ll,chash> aBetterHashMap;
const ll mod=1e9+7;

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<fixed<<setprecision(25);
    ll n,x,y;
    cin>>n;
    set<ll>adj[n];
    ll a[n];
    for(int i=1;i<n;++i){
        cin>>x>>y;
        --x,--y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    for(int i=0;i<n;++i){
        cin>>a[i];
        --a[i];
    }
    if(a[0]!=0){
        cout<<"No\n";
        return 0;
    }
    ll i=1,j=0;
    bool vis[n];
    for(int i=0;i<n;++i)
        vis[i]=0;
    vis[a[0]]=1;
    while(j<i&&i<n){
        while(i<n&&adj[a[j]].find(a[i])!=adj[a[j]].end()){
            if(vis[a[i]]==true){
                cout<<"No\n";
                return 0;
            }
            vis[a[i]]=true;
            ++i;
        }
        bool chk=true;
        for(auto k:adj[a[j]])
            chk&=vis[k];
        if(!chk){
            cout<<"No\n";
            return 0;
        }
        ++j;
    }
    if(i<n)
        cout<<"No\n";
    else
        cout<<"Yes\n";
    return 0;
}
