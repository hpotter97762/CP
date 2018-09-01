#include<iostream>
#include<cstring>
using namespace std;

int main() {
  int n,k,time=0,i;
  cin>>n>>k;
  char c[n][101];
  char pass[101];
  int a[101]={0};
  for(i=0;i<n;i++){
    cin>>c[i];
    a[strlen(c[i])]++;
  }
  cin>>pass;
  for(i=1;i<strlen(pass);i++){
    time+=a[i];
  }
  cout<<(time+(time/k)*5+1)<<' '<<(time+a[i]+((time + a[i]-1)/k)*5);
  return 0;
}