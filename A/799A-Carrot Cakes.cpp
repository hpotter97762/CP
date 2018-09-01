#include<iostream>
#include <cmath>
using namespace std;

int main(){
	int n,k,t,d;
	cin>>n>>t>>k>>d;
	int num=ceil(n*1.0/k);
	int s=d/t;
	if(num>1+s)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}