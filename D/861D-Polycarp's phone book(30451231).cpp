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
//#define e 2.7182818284590452353602874713526624977572

using namespace std;
const ll mod=1e9+7,phimod=1e9+6;

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

inline string read(){
    string s;
    for(int i=0;i<9;++i)
        s+=getchar();
    getchar();
    return s;
}

vector<string> sub(string s){
    vector<string> ans;
    unordered_map<string,bool>vis;
    for(int j=1;j<=9;++j){
		for(int i=0;i<=9-j;++i) {
			if (!vis[s.substr(i,j)]++)
				ans.push_back(s.substr(i,j));
		}
	}
	return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n=rl();
    vector<string> s(n);
    unordered_map<string,bool>mp;
    for(int k=0;k<n;++k){
        s[k]=read();
        vector<string> subs=sub(s[k]);
        for(int i=0;i<subs.size();++i){
            if(mp.find(subs[i])==mp.end())
                mp[subs[i]]=1;
            else
                mp[subs[i]]=0;
        }
    }
    vector<string> ans(n);
    for(int i=0;i<n;++i){
        for(int j=1;j<=9;++j){
            for(int k=0;k<=9-j;++k){
                if(mp[s[i].substr(k,j)]){
                    ans[i]=s[i].substr(k,j);
                    goto NEXT;
                }
            }
        }
        NEXT:;
    }
    for(int i=0;i<n;++i)
        cout<<ans[i]<<'\n';
    return 0;
}