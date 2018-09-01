#include<iostream>
using namespace std;

int gcd(int a,int b){
	if(a%b==0)
		return b;
	else
		return gcd(b,a%b);
}

int main(){
	int n,m,z;
	cin>>n>>m>>z;
	cout<<(gcd(n,m)*z)/(m*n);
	return 0;
}