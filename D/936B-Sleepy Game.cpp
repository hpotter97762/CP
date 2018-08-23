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
vector<vi> adj;
vi vis,visCyc;
bool cycle=false,endPt=false,oddEven=false,push=true;
ll enpt;
vi stk,stk2;

void dfs(ll src,bool val){
    if(push)
        stk.push_back(src);
    if(vis[src]!=-1){
        if(vis[src]!=val){
            oddEven=true;
            push=false;
        }
        else if(push)
            stk.pop_back();
        if(visCyc[src])
            cycle=true;
        return;
    }
    vis[src]=val;
    visCyc[src]=1;
    if(adj[src].size()==0){
        endPt=true;
        enpt=src;
        if(vis[src]){
            oddEven=true;
            push=false;
        }
    }
    for(auto i:adj[src])
        dfs(i,!val);
    if(push)
        stk.pop_back();
    visCyc[src]=0;
}

void dfs2(ll src,ll en,vi &stk1){
    vis[src]=1;
    if(push)
        stk1.push_back(src);
    if(src==en)
        push=false;
    for(auto i:adj[src])
        if(!vis[i])
            dfs2(i,en,stk1);
    if(push)
        stk1.pop_back();
}

void printAns(ll st){
    fill(vis.begin(),vis.end(),0);
    push=true;
    dfs2(stk.back(),enpt,stk2);
    if((stk.size()+stk2.size())%2==0){
        ll mdpt=stk.back();
        stk.clear();
        push=true;
        fill(vis.begin(),vis.end(),0);
        dfs2(st,mdpt,stk);
    }
    for(int i=0;i<stk.size();++i)
        cout<<stk[i]+1<<' ';
    for(int i=1;i<stk2.size();++i)
        cout<<stk2[i]+1<<' ';
    cout<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m;
    cin>>n>>m;
    adj.resize(n);
    vis.resize(n,-1);
    visCyc.resize(n,0);
    for(int i=0;i<n;++i){
        ll ct,q;
        cin>>ct;
        for(int j=0;j<ct;++j){
            cin>>q;
            --q;
            adj[i].push_back(q);
        }
    }
    ll st;
    cin>>st;
    --st;
    dfs(st,false);
    // cout<<endPt<<' '<<oddEven<<' '<<cycle<<'\n';
    if(endPt){
        if(oddEven){
            cout<<"Win\n";
            printAns(st);
        }
        else if(cycle)
            cout<<"Draw\n";
        else
            cout<<"Lose\n";
    }
    else
        cout<<"Draw\n";
    return 0;
}