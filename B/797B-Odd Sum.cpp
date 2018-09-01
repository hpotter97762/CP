#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int i,ans=0;
	for(i=0;i<n;i++){
		if(a[i]>0)
			ans+=a[i];
	}
	if(ans%2==1){
		cout<<ans<<endl;
		return 0;
	}
	int minpos=100000,maxneg=-100000;
	for(int i=0;i<n;i++){
		if (a[i]<0&&a[i]>maxneg&&-a[i]%2==1)
			maxneg=a[i];
		if(a[i]>0&&a[i]<minpos&&a[i]%2==1)
			minpos=a[i];
	}
	if(minpos>-maxneg&&maxneg!=100000)
		cout<<(ans+maxneg)<<endl;
	else
		cout<<(ans-minpos)<<endl;
	return 0;
}