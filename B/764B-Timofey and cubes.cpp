#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		if(((i%2==0)&&(i<n/2))||(((n-i)%2)&&(i>=n/2.0))){
			cout<<a[n-i-1]<<" ";
		}
		else
			cout<<a[i]<<" ";
	}
	return 0;
}