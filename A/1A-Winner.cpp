#include<iostream>
#include<vector>
#include<limits.h>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<string> s;
    string test;
    vector<pair<int,int> > sco[n];
    int score,sc[n],p;
    for(int i=0;i<n;i++)
        sc[i]=0;
    for(int i=0;i<n;i++){
        cin>>test>>score;
        int j;
        p=s.size();
        for(j=0;j<p;j++){
            if(test.compare(s[j])==0)
                break;
        }
        if(j==p){
            s.push_back(test);
        }
        sco[j].push_back(make_pair(score,i));
        sc[j]+=score;
    }
    int max=0,ind=-1;
    p=s.size();
    for(int i=0;i<p;i++){
        if(max<sc[i])
            max=sc[i];
    }
    int min=INT_MAX;
    for(int i=0;i<p;i++){
        if(sc[i]==max){
            int j;
            int check=0;
            for(j=0;j<sco[i].size();j++){
                check+=sco[i][j].first;
                if(check>=max)
                    break;
            }
            if(min>sco[i][j].second){
                min=sco[i][j].second;
                ind=i;
            }
        }
    }
    cout<<s[ind]<<endl;
    return 0;
}