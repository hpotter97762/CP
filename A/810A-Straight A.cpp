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
    int n,k;
    cin>>n>>k;
    int a[n];
    int sum=0;
    for(int i=0;i<n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    int p=ceil(((ld)n*(k-0.5)-sum)*2);
    cout<<max(p,0)<<'\n';
    return 0;
}