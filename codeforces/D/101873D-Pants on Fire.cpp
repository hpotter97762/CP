#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define fs first
#define sc second
#define INIT std::ios_base::sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(25);
#define pi 3.141592653589793238462643383279502884197
//#define e 2.7182818284590452353602874713526624977572
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef std::vector<ll> vi;
typedef std::vector<bool> vb;
typedef std::vector<char> vc;
typedef std::pair<ll,ll> pii;
typedef std::vector<pii> vii;
using namespace std;
using namespace __gnu_pbds;
//Debugging Code
template<typename T>
void prn(T first) {
	cout << first << "\n";
}
template<typename T, typename... Args>
void prn(T first, Args... args) {
	cout << first << " ";
	prn(args...);
}
//HashMap
const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
	int operator()(int x) const { return (x ^ RANDOM); }
};
gp_hash_table<int,ll,chash> hashMap;
const ll mod=1e9+7;
//Random Number Generator
inline ull Rand(ll a,ll b){
	uniform_int_distribution<>dis(a,b);
	mt19937_64 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
	return dis(gen);
}
//##########################################################################################//
//Actual code starts here//
set<ll> adj[200];

bool check(ll src,ll dest,ll par=-1){
	if(src==dest)
		return true;
	bool ret=false;
	for (auto i:adj[src]){
		if(i!=par)
			ret|=check(i,dest,src);
		if(ret)
			break;
	}
	return ret;
}

int main(){
	INIT;
	ll n,m;
	cin>>n>>m;
	string s,a,b,c,t;
	map<string,ll>mp;
	ll val=0;
	for(int i=0;i<n;++i){
		cin>>s>>a>>b>>c>>t;
		if(mp.find(s)==mp.end())
			mp[s]=val++;
		if(mp.find(t)==mp.end())
			mp[t]=val++;
		adj[mp[s]].insert(mp[t]);
	}
	while(m--){
		cin>>s>>a>>b>>c>>t;
		if(mp.find(s)==mp.end()||mp.find(t)==mp.end()){
			cout<<"Pants on Fire\n";
			continue;
		}
		ll sint=mp[s],tint=mp[t];
		if(check(sint,tint))
			cout<<"Fact\n";
		else if (check(tint,sint))
			cout<<"Alternative Fact\n";
		else
			cout<<"Pants on Fire\n";
	}
	return 0;
}
