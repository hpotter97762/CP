#include<iostream>
#include <cmath>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;++i){
        cin>>a[i];
	}
	int start=-1,max=1;
	for(int i=1;i<n;++i){
        if(a[i]>a[i-1]&&start==-1)
            start=i-1;
        if(a[i]<=a[i-1]){
            if(start!=-1&&max<i-start)
                max=i-start;
            start=-1;
        }
	}
	if(max<n-start&&start!=-1)
        max=n-start;
	cout<<max<<'\n';
}