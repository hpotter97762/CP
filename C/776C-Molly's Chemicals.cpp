#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	ll n,k;
	map<ll,ll>mp;
	cin>>n>>k;
	ll a,s=0,cnt=0;
	mp[0]=1;
	for(ll i=0;i<n;++i){
		cin>>a;
		s+=a;
		ll tmp=1;
		if(abs(k)==1){
			if(k==-1){
				cnt+=mp[s+1];
			}
			cnt+=mp[s-1];
		}
		else{
			ll mx=1e15;
			for(ll j=1;j<=mx;j*=k){
				ll tmp=-j+s;
				cnt+=mp[tmp];
			}
		}
		mp[s]++;
	}
	cout<<cnt<<'\n';
	return 0;
}