#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    long long int k=n;
    int count=0;
    while(k/10!=0){
        k=k/10;
        count++;
    }
    long long int p=(k+1)*pow(10,count);
    cout<<p-n<<'\n';
    return 0;
}