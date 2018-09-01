#include<bits/stdc++.h>
#define f(i,a,n) for(i=a;i<n;i++)
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    string s;
    bool flag=0;
    int i,r=0,c=0;
    cin>>s;
    if(s[0]=='R'){
        f(i,1,s.size()){
            if(isalpha(s[i]))
                break;
        }
        if(i!=s.size()&&i!=1)
            flag=1;
    }
    if(flag==0){
    r=0,c=0;
        f(i,0,s.size()){
            if(isalpha(s[i]))
                r=r*26+s[i]-'@';
            else if(isdigit(s[i]))
                c=c*10+s[i]-'0';
        }
        cout<<'R'<<c<<'C'<<r;
    }
    else{
    r=0,c=0;
        f(i,1,s.size()){
            if(isalpha(s[i]))
                break;
            r=r*10 +s[i]-'0';
        }
        f(i,i+1,s.size()){
            c=c*10+s[i]-'0';
        }
        char k[6];
        i=0;
        while(c){
            k[i++]=char(c%26+64);
            if(k[i-1]=='@'){
                k[i-1]='Z';
                c=c-26;
            }
            c=c/26;
        }
        for(int j=i-1;j>=0;j--)
            cout<<k[j];
        cout<<r;
    }
    cout<<endl;
}
}