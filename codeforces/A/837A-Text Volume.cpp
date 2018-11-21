#include<bits/stdc++.h>
#define ll unsigned long long int
#define vi vector<int>
using namespace std;

int main()
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    scanf("%d ",&n);
    int cnt=0,ans=0;
    string s;
    getline(cin,s);
    for(int i=0;i<n;++i){
        if(s[i]==' '){
            ans=max(ans,cnt);
            cnt=0;
        }
        else if(s[i]>='A'&&s[i]<='Z')
            cnt++;
    }
    cout<<max(ans,cnt)<<'\n';
    return 0;
}