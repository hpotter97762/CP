#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define ld long double
#define ll long long int
using namespace std;


int main() {
    int n,f;
    cin>>n>>f;
    int k[n],l[n];
    for(int i=0;i<n;++i)
        cin>>k[i]>>l[i];
    int inc[n];
    for(int i=0;i<n;++i){
        if(l[i]-k[i]>=k[i])
            inc[i]=k[i];
        else
            inc[i]=max(l[i]-k[i],0);
    }
    sort(inc,inc+n);
    ll sum=0;
    for(int i=n-1;i>=n-f;--i)
        sum+=inc[i];
    for(int i=0;i<n;++i){
        sum+=min(l[i],k[i]);
    }
    cout<<sum<<'\n';
    return 0;
}