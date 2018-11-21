#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long int
#define ld long double
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int p[n],tmp[n];
    for(int i=0;i<n;++i)
        cin>>p[i];
    for(int i=0;i<m;++i){
        int l,r,x;
        cin>>l>>r>>x;
        int count=0;
        for(int j=l-1;j<r;++j){
            if(p[j]<p[x-1])
                count++;
        }
        if(l+count-1==x-1)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}