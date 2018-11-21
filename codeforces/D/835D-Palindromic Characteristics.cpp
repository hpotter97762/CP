#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;
int **dp;
string s;
int n;

void init(){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            dp[i][j]=0;
    }
    bool P[n][n];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            P[i][j]=false;
    }
    for(int i=0;i<n;i++)
        P[i][i]=true,dp[i][i]=1;
    for (int i=0;i<n-1;i++){
        if (s[i]==s[i+1]){
            P[i][i+1]=true;
            dp[i][i+1]=2;
        }
    }
    for (int len=2;len<n;len++){
        for (int i=0;i<n-len;i++){
            int j=len+i;
            if (s[i]==s[j]&&P[i+1][j-1])
                P[i][j]=true;
            if (P[i][j]==true)
                dp[i][j]=1+dp[i][i+(len+1)/2-1];
            else
                dp[i][j]=0;
        }
    }
}

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    n=s.size();
    dp=new int*[n];
    for(int i=0;i<n;++i)
        dp[i]=new int[n];
    init();
    vector<int>ans(n,0);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            for(int k=0;k<dp[i][j];++k)
                ans[k]++;
        }
    }/*
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            cout<<dp[i][j]<<" ";
        cout<<'\n';
    }*/
    for(int i=0;i<n;++i)
        cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
}