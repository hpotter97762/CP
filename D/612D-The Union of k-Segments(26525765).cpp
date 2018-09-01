#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct seg{
    int i,j;
};

bool cmp(seg a,seg b){
    if(a.i==b.i)
        return a.j>b.j;
    return a.i<b.i;
}

void comseg(vector<seg> a,int n,int k){
    priority_queue<int,vector<int>,greater<int> >en;
    vector<seg> ans;
    seg b;
    for(int i=0;i<k;i++)
        en.push(a[i].j);
    int s=a[k-1].i,e=en.top();
    en.pop();
    for(int i=k;i<n;i++){
        en.push(a[i].j);
        if(e<s){
            e=en.top();
            s=a[i].i;
        }
        else if(a[i].i>e){
            b.i=s;
            b.j=e;
            ans.push_back(b);
            e=en.top();
            s=a[i].i;
        }
        else if(en.top()>e){
            e=en.top();
        }
        en.pop();
    }
    b.i=s;
    b.j=e;
    if(e>=s)
        ans.push_back(b);
    int z=ans.size();
    cout<<z<<endl;
    for(int i=0;i<z;i++)
        cout<<ans[i].i<<" "<<ans[i].j<<endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n,k,x,y;
    cin>>n>>k;
    vector<seg> a;
    seg b;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        b.i=x,b.j=y;
        a.push_back(b);
    }
    sort(a.begin(),a.end(),cmp);
    comseg(a,n,k);
    return 0;
}