#include<bits/stdc++.h>
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
#define e 2.7182818284590452353602874713526624977572

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

int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	ll n=rl();
	string s;
	vb q(26,1),r(26);
	ll val=0;
	char ans=0;
	for(int i=0;i<n;++i){
        char c=getchar();
        getchar();
        read(s);
        if(ans){
            if(c=='!'||(c=='?'&&s[0]!=ans))
                ++val;
            continue;
        }
        fill(r.begin(),r.end(),0);
        for(int i=0;i<s.size();++i)
            r[s[i]-'a']=1;
        if(c=='!'){
            for(int i=0;i<26;++i)
                q[i]=q[i]&r[i];
        }
        else if(c=='.'){
            for(int i=0;i<26;++i)
                q[i]=q[i]&(!r[i]);
        }
        else if(i!=n-1){
            q[s[0]-'a']=0;
        }
        ll cnt=0;
        for(int i=0;i<26;++i){
            if(!cnt)
                ans='a'+i;
            cnt+=q[i];
        }
        if(cnt!=1)
            ans=0;
	}
	cout<<val<<'\n';
	return 0;
}