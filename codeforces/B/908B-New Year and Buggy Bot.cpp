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
const int mod=1e9+7;

inline ll rl(){
    ll res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}

inline void read(string &s){
    s="";
    char c=getchar();
    while(c!='\n'&&c!=' '){
        s+=c;
        c=getchar();
    }
}
ll ans=0;
string s;
pii st1,en1;
vii a(4);
vector<string> v;
ll n,m;

bool check(vii &a){
    pii st=st1,en=en1;
    for(int i=0;i<s.size();++i){
        st.fs+=a[s[i]-'0'].fs;
        st.sc+=a[s[i]-'0'].sc;
        if(st.fs<0||st.fs>=n||st.sc<0||st.sc>=m)
            break;
        if(v[st.fs][st.sc]=='#')
            return false;
        if(st.fs==en.fs&&st.sc==en.sc){
            return true;
        }

    }
    return false;
}

void call(int l, int r)
{
    int i;
    if (l == r){
        if(check(a))
            ans++;
    }
    else{
        for (i = l; i <= r; i++){
            pii tmp=a[l];
            a[l]=a[i];
            a[i]=tmp;
            call(l+1, r);
            tmp=a[l];
            a[l]=a[i];
            a[i]=tmp;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    a[0]={0,1},a[1]={1,0},a[2]={0,-1},a[3]={-1,0};
    n=rl(),m=rl();
    v.resize(n);
    for(int i=0;i<n;++i)
        read(v[i]);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(v[i][j]=='S')
                st1={i,j};
            if(v[i][j]=='E')
                en1={i,j};
        }
    }
    read(s);
    call(0,3);
    cout<<ans<<'\n';
    return 0;
}