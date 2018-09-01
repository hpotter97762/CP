#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size(),l;
    l=n;
    int i=0;
    --l;
    int count=0;
    while(i<l){
        if(s[i]!=s[l])
            count++;
        i++;
        --l;
    }
    if(count==1)
        cout<<"YES\n";
    else if(count==0&&n%2==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}