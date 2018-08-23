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
    ll n,m;
    cin>>n>>m;
    vector<vc>a(n,vc(m));
    pii s,t;
    for(ll i=0;i<n;++i)
        for(ll j=0;j<m;++j){
            cin>>a[i][j];
            if(a[i][j]=='S')
                s={i,j};
            if(a[i][j]=='T')
                t={i,j};
        }
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<m;++j)
    //         cout<<a[i][j]<<' ';
    //     cout<<'\n';
    // }
    // cout<<s.fs<<' '<<s.sc<<' '<<t.fs<<' '<<t.sc<<'\n';
    ll mn,mx;
    for(ll i=s.fs;;++i){
        if(i==n||a[i][s.sc]=='*'){
            mx=i-1;
            // cout<<mx<<'\n';
            break;
        }
    }
    for(ll i=t.fs;;++i){
        if(i==n||a[i][t.sc]=='*'){
            mx=min(mx,i-1);
            // cout<<mx<'\n';
            break;
        }
    }
    for(ll i=s.fs;;--i){
        if(i==-1||a[i][s.sc]=='*'){
            mn=i+1;
            // cout<<mn<<'\n';
            break;
        }
    }
    for(ll i=t.fs;;--i){
        if(i==-1||a[i][t.sc]=='*'){
            mn=max(mn,i+1);
            // cout<<mn<<'\n';
            break;
        }
    }
    std::vector<vi> v(n,vi(m));
    for(ll i=0;i<n;++i)
        v[i][0]=0;
    for(ll i=0;i<n;++i){
        for(ll j=1;j<m;++j){
            v[i][j]=(a[i][j-1]=='*')?j:v[i][j-1];
        }
    }
    ll tp=max(s.sc,t.sc),tmp=min(s.sc,t.sc);
    for(ll i=mn;i<=mx;++i){
        if(v[i][tp]<=tmp){
            cout<<"YES\n";
            return 0;
        }
    }
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<m;++j)
    //         cout<<v[i][j]<<' ';
    //     cout<<'\n';
    // }
    for(ll i=s.sc;;++i){
        if(i==m||a[s.fs][i]=='*'){
            mx=i-1;
            break;
        }
    }
    // cout<<mx<<'\n';
    for(ll i=t.sc;;++i){
        if(i==m||a[t.fs][i]=='*'){
            mx=min(mx,i-1);
            break;
        }
    }
    // cout<<mx<<'\n';
    for(ll i=s.sc;;--i){
        if(i==-1||a[s.fs][i]=='*'){
            mn=i+1;
            break;
        }
    }
    // cout<<mn<<'\n';
    for(ll i=t.sc;;--i){
        if(i==-1||a[t.fs][i]=='*'){
            mn=max(mn,i+1);
            break;
        }
    }
    // cout<<mn<<'\n';
    for(ll i=0;i<m;++i)
        v[0][i]=0;
    for(ll i=1;i<n;++i){
        for(ll j=0;j<m;++j){
            v[i][j]=(a[i-1][j]=='*')?i:v[i-1][j];
        }
    }
    // cout<<mn<<' '<<mx<<'\n';
    tp=max(s.fs,t.fs),tmp=min(s.fs,t.fs);
    for(ll i=mn;i<=mx;++i){
        if(v[tp][i]<=tmp){
            cout<<"YES\n";
            return 0;
        }
    }
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<m;++j)
    //         cout<<v[i][j]<<' ';
    //     cout<<'\n';
    // }
    cout<<"NO\n";
    return 0;
}