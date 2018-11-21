#include<vector>
#include<iostream>
using namespace std;

int main(){
    int n,m,k;
    int min=10000;
    cin>>n>>m>>k;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    m--;
    int i=0;
    for(;i<m;i++){
        if(min>m-i&&k>=a[i]&&a[i]!=0){
            min=m-i;
        }
    }
    i++;
    for(;i<n;i++){
        if(min>i-m&&k>=a[i]&&a[i]!=0){
            min=i-m;
        }
    }
    cout<<10*min<<'\n';
    return 0;
}