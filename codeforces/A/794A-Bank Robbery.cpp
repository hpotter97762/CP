#include<iostream>
#include <algorithm>
#include<cmath>
#define ll long long int
using namespace std;

int binse(int *a,int start,int end,int key){
    while(start<=end){
        int mid=(start+end)/2;
        if(a[mid]>key)
            end=mid-1;
        else if(a[mid]<key)
            start=mid+1;
        else{
            if(a[mid-1]!=key&&mid-1>=0)
                return mid;
            else
                end=mid-1;
        }
    }
    return start;
}

int binst(int *a,int start,int end,int key){
    int l=end;
    while(start<=end){
        int mid=(start+end)/2;
        if(a[mid]>key)
            end=mid-1;
        else if(a[mid]<key)
            start=mid+1;
        else{
            if(a[mid+1]!=key&&mid+1<=l)
                return mid;
            else
                start=mid+1;
        }
    }
    return end;
}

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    int n;
    cin>>n;
    int s[n];
    for(int i=0;i<n;++i)
        cin>>s[i];
    sort(s,s+n);
    int start=binst(s,0,n-1,b);
    int end=binse(s,0,n-1,c);
    cout<<end-start-1<<'\n';
    return 0;
}
