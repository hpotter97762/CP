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

ll gcd(ll a,ll b){
	while(a&&b){
		ll tp=b;
		b=a%b;
		a=tp;
	}
	return a+b;
}

int main(){
    INIT;
    ll n;
    cin>>n;
    ll x[n],y[n];
    for(int i=0;i<n;++i)
    	cin>>x[i]>>y[i];
    ll bound=0;
    ll area=0;
    for(int i=0;i<n;++i){
    	bound+=gcd(abs(x[(i+1)%n]-x[i]),abs(y[(i+1)%n]-y[i]));
    	area+=(x[i]*y[(i+1)%n]-y[i]*x[(i+1)%n]);
    }
    cout<<(abs(area)-bound)/2+1<<'\n';
    return 0;
}
