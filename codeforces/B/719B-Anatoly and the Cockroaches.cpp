#include<iostream>
#include<string>
using namespace std;

int min(int a,int b){
    if(a<b)
        return a;
    return b;
}

int main(){
    int n;
    cin>>n;
    char s[n+1];
    cin>>s;
    int r1=0,b1=0,r2=0,b2=0;
    for(int i=0;i<n;i++){
        if(i%2){
            if(s[i]=='b')
                b1++;
            else
                r1++;
        }
        else{
            if(s[i]=='b')
                b2++;
            else
                r2++;
        }
    }
    int ansr,ansb,temp;
    temp=min(r1,b2);
    ansr=r1+b2-temp;
    temp=min(r2,b1);
    ansb=r2+b1-temp;
    cout<<min(ansr,ansb);
    return 0;
}