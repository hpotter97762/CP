#include<iostream>
#include<string>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s,t;
    cin>>s;
    cin>>t;
    for(int i=0;i<s.size();i++){
        if(s[i]<t[i]){
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<t<<'\n';
    return 0;
}