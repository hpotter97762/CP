#include<bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    char a[n][m];
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            cin>>a[i][j];
    int i;
    for(i=1;i<m;++i)
        if(a[0][i]!=a[0][i-1])
            break;
    if(i==m){
        if(n%3!=0)
            goto EXIT;
        for(i=0;i<n/3;++i){
            for(int j=0;j<m;++j){
                if(a[i][j]!=a[0][0]){
                    goto EXIT;
                }
            }
        }
        for(;i<2*n/3;++i){
            for(int j=0;j<m;++j){
                if(a[i][j]!=a[n/3][0]){
                    goto EXIT;
                }
            }
        }
        for(;i<n;++i){
            for(int j=0;j<m;++j){
                if(a[i][j]!=a[n-1][0]){
                    goto EXIT;
                }
            }
        }
        if(a[0][0]==a[n/3][0]||a[n/3][0]==a[n-1][0]||a[n-1][0]==a[0][0])
            goto EXIT;
        else{
            cout<<"YES\n";
            return 0;
        }
    }
    else{
        if(m%3!=0)
            goto EXIT;
        int j;
        for(i=0;i<n;++i){
            for(j=0;j<m/3;++j){
                if(a[i][j]!=a[0][0]){
                    goto EXIT;
                }
            }
        }
        for(i=0;i<n;++i){
            for(j=m/3;j<2*m/3;++j){
                if(a[i][j]!=a[0][m/3]){
                    goto EXIT;
                }
            }
        }
        for(i=0;i<n;++i){
            for(j=2*m/3;j<m;++j){
                if(a[i][j]!=a[0][m-1]){
                    goto EXIT;
                }
            }
        }
        if(a[0][0]==a[0][m/3]||a[0][m/3]==a[0][m-1]||a[0][m-1]==a[0][0])
            goto EXIT;
        else{
            cout<<"YES\n";
            return 0;
        }
    }
    EXIT:
        cout<<"NO\n";
    return 0;
}