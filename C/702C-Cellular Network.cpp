#include<iostream>
#include <algorithm>
#define ll long long int
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
	ll n,m;
	cin>>n>>m;
	ll a[n],b[m];
	for(ll i=0;i<n;++i){
        cin>>a[i];
	}
	for(ll i=0;i<m;++i)
        cin>>b[i];
    sort(b,b+m);
    sort(a,a+n);
    ll tow[n];
    ll i,j=0;
    for(i=0;i<n;i++){
        while(b[j]<a[i]&&j<m)
            j++;
        if(j==0)
            tow[i]=b[j]-a[i];
        else if(j==m)
            tow[i]=a[i]-b[j-1];
        else
            tow[i]=min(b[j]-a[i],a[i]-b[j-1]);
    }
    ll max=0;
    for(ll i=0;i<n;i++){
        if(max<tow[i])
            max=tow[i];
    }
    cout<<max<<'\n';
    return 0;
}