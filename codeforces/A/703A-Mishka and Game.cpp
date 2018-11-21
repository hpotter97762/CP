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
    int n;
    cin>>n;
    int m,mis=0,c,ch=0;
    for(int i=0;i<n;++i){
        cin>>m>>c;
        if(m>c)
            mis++;
        else if(c>m)
            ch++;
    }
    if(mis>ch)
        cout<<"Mishka\n";
    else if(ch>mis)
        cout<<"Chris\n";
    else
        cout<<"Friendship is magic!^^\n";
    return 0;
}