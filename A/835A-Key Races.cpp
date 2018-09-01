#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    ll s,v,w,t,u;
    cin>>s>>v>>w>>t>>u;
    ll first=s*v+2*t;
    ll second=s*w+2*u;
    second>first?cout<<"First\n":((second<first)?cout<<"Second\n":cout<<"Friendship\n");
    return 0;
}