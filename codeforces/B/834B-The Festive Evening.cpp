#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first==b.first)
        return a.second>b.second;
    return a.first<b.first;
}

int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<pair<int,int> >d(26);
    for(int i=0;i<26;++i)
        d[i].first=-1,d[i].second=-1;
    for(int i=0;i<n;++i){
        if(d[s[i]-'A'].first==-1)
            d[s[i]-'A'].first=i;
        else
            d[s[i]-'A'].second=i;
    }
    for(int i=0;i<26;++i){
        if(d[s[i]-'A'].second==-1)
            d[s[i]-'A'].second=d[s[i]-'A'].first;
    }
    int cnt=0,mx=0;
    vector<pair<int,int> > ans;
    for(int i=0;i<26;++i){
        if(d[i].first!=-1){
            ans.push_back(make_pair(d[i].first,1));
            ans.push_back(make_pair(d[i].second,-1));
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();++i){
        cnt+=ans[i].second;
        mx=max(mx,cnt);
    }
    if(mx>k)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}