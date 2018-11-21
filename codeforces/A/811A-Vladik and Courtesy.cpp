#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long int
#define ld long double
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,i=1;
    cin>>a>>b;
    while(a>=0&&b>=0){
        if(i%2==1){
            a-=i;
        }
        else
            b-=i;
        i++;
    }
    if(a>=0)
        cout<<"Valera\n";
    else
        cout<<"Vladik\n";
    return 0;
}