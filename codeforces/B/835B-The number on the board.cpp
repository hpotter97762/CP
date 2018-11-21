#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    ll k;
    string n;
    cin>>k>>n;
    ll sum=0;
    for(int i=0;i<n.size();++i){
        sum+=n[i]-'0';
        n[i]='9'-n[i];
    }
    sort(n.begin(),n.end());
    if(sum>=k)
        cout<<"0\n";
    else{
        ll j=n.size()-1,cnt=0;
        while(sum<k){
            sum+=n[j];
            cnt++;
            --j;
        }
        cout<<cnt<<'\n';
    }
    return 0;
}