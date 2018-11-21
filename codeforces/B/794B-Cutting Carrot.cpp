#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

long double base(long double h){

}

int main(){
    long double n,h;
    cin>>n>>h;
    long double area=0.5*h;
    long double ans[int(n-1)];
    for(int i=0;i<n-1;i++){
        ans[i]=sqrt((i+1)/n)*h;
    }
    for(int i=0;i<n-1;++i)
    cout<<std::setprecision(15)<<ans[i]<<" ";
    return 0;
}