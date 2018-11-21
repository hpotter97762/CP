#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define vi vector<ll>
#define vb vector<bool>
#define vc vector<char>
#define pii pair<ll,ll>
#define vii vector<pair<ll,ll> >
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
#define exp 2.7182818284590452353602874713526624977572

using namespace std;
const int mod=1000000007,sz=20;

inline int ri(){
    int res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}

inline ll rl(){
    ll res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}

struct trie{
    trie *m[2];
    bool c;
    trie(){
        this->m[0]=NULL;
        this->m[1]=NULL;
    }
} *sol=new trie;

void insert1(int a){
    int tp=1<<sz;
    trie *p=sol;
    while(tp){
        bool k=((tp&a)!=0);
        if(p->m[k]==NULL)
            p->m[k]=new trie;
        p=p->m[k];
        tp>>=1;
    }
}
/*
void print(trie *p,int val){
    if(!p->m[0]&&!p->m[1])
        cout<<val<<' ';
    if(p->m[0])
        print(p->m[0],2*val);
    if(p->m[1])
        print(p->m[1],2*val+1);
}*/

bool dfs(trie *p){
    if(p->m[0])
        dfs(p->m[0]);
    if(p->m[1])
        dfs(p->m[1]);
    if(p->m[0]&&p->m[1])
        p->c=p->m[0]->c&p->m[1]->c;
    else if(!p->m[0]&&!p->m[1])
        p->c=1;
    else
        p->c=0;
}

int solve(int a){
    int tp=1<<sz;
    int ans=0;
    trie *p=sol;
    bool k=((tp&a)!=0);
    if(!p->m[k])
        return ans;
    while(tp){
        while(!p->m[k]->c){
            p=p->m[k];
            tp>>=1;
            k=((tp&a)!=0);
            if(!p->m[k])
                return ans;
        }
        ans+=tp;
        k=(k+1)%2;
        if(!p->m[k])
            return ans;
    }
    return ans;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl(),m=rl(),a;
    for(int i=0;i<n;++i){
        a=rl();
        insert1(a);
    }
    dfs(sol);
    a=0;
    while(m--){
        a^=rl();
        cout<<solve(a)<<'\n';
    }
    return 0;
}