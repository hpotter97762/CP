#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#define ll long long int
using namespace std;

struct cap{
    int a,fil,ind;
};

bool cmp(cap a,cap b){
    return a.a<b.a;
}

int main(){
    int n,w;
    cin>>n>>w;
    cap a[n];
    for(int i=0;i<n;++i)
        cin>>a[i].a,a[i].ind=i;
    sort(a,a+n,cmp);
    for(int i=0;i<n;++i){
        a[i].fil=ceil(a[i].a*1.0/2);
        w-=a[i].fil;
    }
    if(w<0){
        cout<<"-1\n";
        return 0;
    }
    for(int i=n-1;i>=0&&w>0;--i){
        if(a[i].a-a[i].fil>=w){
            a[i].fil+=w;
            w=0;
        }
        else{
            w-=(a[i].a-a[i].fil);
            a[i].fil=a[i].a;
        }
    }
    if(w>0)
        cout<<"-1\n";
    else{
        int ans[n];
        for(int i=0;i<n;++i)
            ans[a[i].ind]=a[i].fil;
        for(int i=0;i<n;++i)
            cout<<ans[i]<<" ";
        cout<<'\n';
    }
    return 0;
}