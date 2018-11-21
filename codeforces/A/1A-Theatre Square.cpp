#include<iostream>
#include<cmath>
#define ll long long int
using namespace std;

int main(){
    ll m,n,k;
    cin>>m>>n>>k;
    ll ans=ceil((m*1.0)/k)*ceil((n*1.0)/k);
    cout<<ans;
    return 0;
}