#include <bits/stdc++.h>
using namespace std;

int main()
{
    char s;
    int st,en;
    cin>>s;
    if(s=='^')
        st=1;
    else if(s=='>')
        st=2;
    else if(s=='<')
        st=4;
    else
        st=3;
    cin>>s;
    if(s=='^')
        en=1;
    else if(s=='>')
        en=2;
    else if(s=='<')
        en=4;
    else
        en=3;
    int n;
    cin>>n;
    n%=4;
    if(n==0||n==2){
        cout<<"undefined\n";
    }
    else if(n==(en-st+4)%4)
        cout<<"cw\n";
    else
        cout<<"ccw\n";
    return 0;
}