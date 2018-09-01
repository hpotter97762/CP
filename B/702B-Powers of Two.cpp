#include<iostream>
#include <algorithm>
#include<cmath>
#define ll long long int
using namespace std;

ll binstart(ll *a,ll start,ll end,ll key){
    while(start<=end){
        ll mid=(start+end)/2;
        if(a[mid]>key)
            end=mid-1;
        else if(a[mid]<key)
            start=mid+1;
        else{
            if(a[mid-1]!=key&&mid-1>=0)
                return mid;
            else
                end=mid-1;
        }
    }
    return start;
}

ll binend(ll *a,ll start,ll end,ll key){
    ll k=end;
    while(start<=end){
        ll mid=(start+end)/2;
        if(a[mid]>key)
            end=mid-1;
        else if(a[mid]<key)
            start=mid+1;
        else{
            if(a[mid+1]!=key&&mid+1<=k)
                return mid+1;
            else
                start=mid+1;
        }
    }
    return start;
}

ll bin(ll *a,ll start,ll end, ll key){
    return binend(a,start,end,key)-binstart(a,start,end,key);
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;++i){
        cin>>a[i];
	}
    sort(a,a+n);
    ll count=0;
    --n;
    for(ll i=0;i<n;i++){
        ll k=log2(a[i]);
        ll p=pow(2,k);
        while(p-a[i]<a[i])
            p=p*2;
        while(p<=a[n]+a[i]){
            ll l=bin(a,i+1,n,p-a[i]);
            count+=l;
            p=p*2;
        }
    }
    cout<<count<<'\n';
    return 0;
}