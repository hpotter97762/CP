#include<iostream>
#include<string>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int count=0,flag=0;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='V'&&s[i+1]=='K')
            count++,++i;
        else if(s[i+1]=='V'&&s[i+2]=='K'&&i+2<s.size()){
            count++,i+=2;
        }
        else if(s[i]!='K'||s[i+1]!='V')
            flag=1,++i;
    }
    if(flag==1)
        count++;
    cout<<count<<'\n';
    return 0;
}