#include<iostream>
#include<cmath>
#include<iomanip>
#define ll long long int
using namespace std;

int main(){
    ll n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;++i)
        cin>>a[i];
    ll sum=0;
    int i=0;
    for(i=0;i<k;++i)
        sum+=a[i];
    ll ans=sum;
    for(;i<n;++i){
        sum+=(a[i]-a[i-k]);
        ans+=sum;
    }
    cout<<std::setprecision(20)<<(long double)ans/(n-k+1)<<'\n';
    return 0;
}