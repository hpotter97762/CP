#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	string a,b,s;
	cin>>a>>b;
	int n;
	cin>>n;
	cout<<a<<" "<<b<<'\n';
	for(int i=0;i<n;++i){
		cin>>s;
		if(a.compare(s)==0)
			cin>>a;
		else
			cin>>b;
		cout<<a<<" "<<b<<'\n';
	}
	return 0;
}