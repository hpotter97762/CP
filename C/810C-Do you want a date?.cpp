#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define ld long double
#define ll long long int
using namespace std;
const ll mod=1000000007;

int main() {
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    ll max=0;
    ll min=0;
    ll k=1;
    for(ll i=0;i<n;++i){
        max=(max+(k*a[i])%mod)%mod;
        k=(k*2)%mod;
    }
    k=1;
    for(ll i=n-1;i>=0;--i){
        min=(min+(k*a[i])%mod)%mod;
        k=(k*2)%mod;
    }
    cout<<(max-min+mod)%mod<<'\n';
    return 0;
}