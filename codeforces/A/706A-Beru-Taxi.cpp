#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    long double temp=300,t;
    int a,b,n;
    cin>>a>>b>>n;
    while(n--){
        int x,y,v;
        cin>>x>>y>>v;
        t=(sqrt(pow((x-a),2)+pow((y-b),2)))/v;
        if(temp>t)
        temp=t;
    }
    std::cout<<std::setprecision(9)<<temp<<'\n';
    return 0;
}