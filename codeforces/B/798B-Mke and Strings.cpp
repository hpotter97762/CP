#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    char s[n][51];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int k=strlen(s[0]);
    char p[k][k+1];
    for(int i=0;i<k;i++){
        int j;
        for(j=0;j<k;j++){
            p[i][j]=s[0][(i+j)%k];
        }
        p[i][j]=0;
    }
    vector<int>in[n];
    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<k;j++){
            if(strcmp(s[i],p[j])==0){
                in[i].push_back(j);
            }
        }
        if(j==k&&in[i].empty()){
            cout<<"-1\n";
            return 0;
        }
    }
    int sum;
    int ant=0,min=200000;
    for(int j=0;j<k;j++){
        sum=j;
        ant=0;
        for(int i=0;i<n;i++){
            int temp=100000;
            for(int az=0;az<in[i].size();az++){
                int temp1=(sum-in[i][az]+k)%k;
                if(temp>temp1)
                    temp=temp1;
            }
            ant+=temp;
        }
        if(min>ant)
            min=ant;
    }
    cout<<min<<endl;
    return 0;
}