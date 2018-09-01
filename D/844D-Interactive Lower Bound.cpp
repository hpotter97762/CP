#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<ll,ll>
#define vii vector<pair<ll,ll> >
#define pi 3.141592653589793238462643383279502884197
//#define e 2.7182818284590452353602874713526624977572

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
    srand(time(NULL));
    int left=2000;
    list<pii >indl;
    map<int,bool> mp;
    int val,nex;
    int n=read_int(),st=read_int(),x=read_int();
    cout<<"? "<<st<<'\n';
    fflush(stdout);
    cin>>val>>nex;
    indl.push_back(make_pair(val,nex));
    mp[st]=1;
    mp[nex]=1;
    --left;
    if(left<n-1){
        while(left>1000){
            int tmp=(rand()+rand())%n+1;
            while(mp.find(tmp)!=mp.end())
                tmp=rand()%n+1;
            mp[tmp]=1;
            cout<<"? "<<tmp<<'\n';
            fflush(stdout);
            cin>>val>>nex;
            mp[nex]=1;
            auto it=indl.begin();
            for(;it!=indl.end()&&it->first<val;++it);
            if(it->first!=val)
                indl.insert(it,make_pair(val,nex));
            left--;
            if(nex==x)
                break;
        }
    }
    auto it=indl.begin();
    auto prev=it;
    while(it!=indl.end()&&it->first<x){prev=it;it++;}
    if(it->first==x){
        cout<<"! "<<x<<'\n';
        fflush(stdout);
        return 0;
    }
    if(prev->second==-1&&prev->first<x){
        cout<<"! -1\n";
        fflush(stdout);
        return 0;
    }
    if(prev->first>=x){
        cout<<"! "<<prev->first<<'\n';
        fflush(stdout);
        return 0;
    }
    cout<<"? "<<prev->second<<'\n';
    fflush(stdout);
    cin>>val>>nex;
    --left;
    while(val<x&&left--){
        if(nex==-1){
            cout<<"! -1\n";
            fflush(stdout);
            return 0;
        }
        cout<<"? "<<nex<<'\n';
        fflush(stdout);
        cin>>val>>nex;
    }
    cout<<"! ";
    if(val>=x)
        cout<<val<<'\n';
    else
        cout<<"-1\n";
    fflush(stdout);
    return 0;
}