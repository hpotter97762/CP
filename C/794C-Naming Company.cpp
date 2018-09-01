#include<iostream>
#include <algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<vector>
#define ll long long int
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s;
    cin>>t;
    int n=s.size();
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    vector<char> ans(n+1);
    ans[n]=0;
    int j=0,k=n-1,l=0,i;
    for(i=0;i<n&&s[j]<t[k];i++,++l){
        if(i%2==0){
            ans[l]=s[j];
            j++;
        }
        else{
            ans[l]=t[k];
            --k;
        }
    }
    int places=n-i;
    if(places%2==0){
        k-=places/2;
        k++;
        j+=places/2;
        j--;
    }
    else{
        if(i%2==0){
            j+=places/2;
            k-=places/2;
            k++;
        }
        else{
            j+=places/2;
            j--;
            k-=places/2;
        }
    }
    int p=n-1;
    for(;i<n;++i){
        if(i%2==0)
            ans[p--]=s[j--];
        else
            ans[p--]=t[k++];
    }
    int z=0;
    while(z<n){
        cout<<ans[z];
        ++z;
    }
    return 0;
}