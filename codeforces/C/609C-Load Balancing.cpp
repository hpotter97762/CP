#include<iostream>
#include<cmath>
using namespace std;

int main(){
int n;
cin>>n;
int a[n],sum=0;
for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
}
int mean,k;
mean=sum/n;
k=sum%n;
int diff=0,add=0;
for(int i=0;i<n;i++){
    if(a[i]>mean&&k!=0){
        k--;
        diff=diff+a[i]-mean-1;
    }
    else{
        if(a[i]>mean)
            diff+=a[i]-mean;
        else
            add+=mean-a[i];
    }
}
cout<<max(add,diff);
return 0;
}