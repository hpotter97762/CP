#include<iostream>
#include<map>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    if(k==1){
        cout<<n<<endl;
        return 0;
    }
    map<int,int> ans;
    vector<bool>a(400,true);
    a[0]=false;
    a[1]=false;
    for(int i=2;i<400;i++){
        if(a[i]==true){
            for(int j=2*i;j<400;j+=i)
                a[j]=false;
        }
    }
    int p=sqrt(n)+1,count=0;
    for(int i=2;i<p&&n>1;i++){
        if(a[i]==true&&n%i==0){
            ans[i]=1;
            n=n/i;
            count++;
            while(n%i==0){
                count++;
                n=n/i;
                ans[i]++;
            }
        }
    }
    if(n!=1){
        ans[n]=1;
        count++;
    }
    if(count<k)
        cout<<"-1 \n";
    else{
        std::map<int,int>::iterator it;
        it=ans.begin();
        int ap=1;
        while(count!=k-1){
            ap=ap*it->first;
            it->second--;
            count--;
            if(it->second==0)
                it++;
        }
        cout<<ap<<" ";
        k--;
        while(k>0){
            cout<<it->first<<" ";
            it->second--;
            if(it->second==0)
                it++;
            k--;
        }
    }
    return 0;
}