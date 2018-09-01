#include<vector>
#include<iostream>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k,p,q;
    cin>>n>>m>>k;
    bool a[n+1];
    int pos=1;
    for(int i=0;i<=n;i++)
        a[i]=false;
    for(int i=0;i<m;i++){
        cin>>p;
        a[p]=true;
    }
    for(int i=0;i<k;i++){
        cin>>p>>q;
        if(a[pos]==true)
            break;
        if(p==pos)
            pos=q;
        else if(q==pos)
            pos=p;
    }
    cout<<pos<<'\n';
    return 0;
}