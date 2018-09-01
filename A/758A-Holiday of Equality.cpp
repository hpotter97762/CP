#include <iostream>
using namespace std;

int main() {
	int n,max=0;
	cin>>n;
	int *a=new int [n];
	for(int j=0;j<n;j++){
		cin>>a[j];
		if(max<a[j])
		max=a[j];
	}
	int sum=0;
	for(int j=0;j<n;j++){
		sum=sum+max-a[j];
	}
	cout<<sum;
	return 0;
}