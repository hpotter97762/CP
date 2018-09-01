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
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n=rl();
	map<string,map<string,bool>>mp;
	map<string,map<string,bool>>check;
	vi a(n);
	for(int i=0;i<n;++i){
        string s;
        read(s);
        ll k=rl();
        for(int j=0;j<k;++j){
            string num;
            read(num);
            if(check[s][num]==0){
                mp[s][num]=1,check[s][num]=1;
                num.erase(num.begin());
                while(num.compare("")!=0){
                    if(check[s][num]==1){
                        mp[s].erase(num);
                    }
                    else
                        check[s][num]=1;
                    num.erase(num.begin());
                }
            }
        }
	}
	cout<<mp.size()<<'\n';
	for(auto i:mp){
        cout<<i.first<<" "<<i.second.size()<<" ";
        for(auto j:i.second)
            cout<<j.first<<' ';
        cout<<'\n';
	}
	return 0;
}