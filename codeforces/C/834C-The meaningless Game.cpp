#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

ll cubrt(ll n){
    ll beg=0,en=1e6;
    while(beg<=en){
        ll mid=beg+(en-beg)/2;
        ll s=mid*mid*mid;
        if(s>n)
            en=mid-1;
        else if(s<n)
            beg=mid+1;
        else
            return mid;
    }
    return en;
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    while(n--){
        ll a,b;
        cin>>a>>b;
        ll crt=cubrt(a*b);
        if(crt*crt*crt==a*b&&a%crt==0&&b%crt==0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}