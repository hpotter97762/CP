#include<bits/stdc++.h>
#define ll long long int
using namespace std;

struct seal{
    int l,b;
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,a,b;
    cin>>n>>a>>b;
    vector<seal> s(n);
    for(int i=0;i<n;++i){
        cin>>s[i].l>>s[i].b;
    }
    int mx=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if((s[i].l+s[j].l<=a&&max(s[i].b,s[j].b)<=b)||(s[i].l+s[j].b<=a&&max(s[i].b,s[j].l)<=b)||(s[i].b+s[j].b<=a&&max(s[i].l,s[j].l)<=b)||(s[i].b+s[j].l<=a&&max(s[i].l,s[j].b)<=b))
                mx=max(mx,s[i].l*s[i].b+s[j].l*s[j].b);
            else if((s[i].l+s[j].l<=b&&max(s[i].b,s[j].b)<=a)||(s[i].l+s[j].b<=b&&max(s[i].b,s[j].l)<=a)||(s[i].b+s[j].b<=b&&max(s[i].l,s[j].l)<=a)||(s[i].b+s[j].l<=b&&max(s[i].l,s[j].b)<=a))
                mx=max(mx,s[i].l*s[i].b+s[j].l*s[j].b);
        }
    }
    cout<<mx<<'\n';
    return 0;
}