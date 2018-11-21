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
    ll n,a,b;
    cin>>n>>a>>b;
    if((a!=1&&b!=1)||(n<4&&n>1&&a==b)){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    vector<vi> adj(n,vi(n,0));
    for(int i=max(a,b)-1;i<n-1;++i)
        adj[i][i+1]=adj[i+1][i]=1;
    if(a==1){
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(i!=j)
                    adj[i][j]=!adj[i][j];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            cout<<adj[i][j];
        cout<<'\n';
    }
    return 0;
}