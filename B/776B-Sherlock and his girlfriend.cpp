#include<bits/stdc++.h>
using namespace std;
vector<bool>prime;

void seive(){
	int i;
	for(i=2;i*i<prime.size();++i){
		if(prime[i]){
			cout<<"1 ";
			for(int j=i*2;j<prime.size();j+=i)
				prime[j]=0;
		}
		else
			cout<<"2 ";
	}
	for(;i<prime.size();++i){
		if(prime[i])
			cout<<"1 ";
		else
			cout<<"2 ";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	/*int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;++i)
		cin>>a[i];
	ll sum=0;
	for(int i=0;i<n;++i){
		if(sum>=*/
	int n;
	cin>>n;
	prime.resize(n+2,1);
	if(n<3)
		cout<<"1\n";
	else
		cout<<"2\n";
	seive();
	cout<<'\n';
	return 0;
}