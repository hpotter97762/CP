#include<iostream>
using namespace std;

int main(){
  int n,count=0,i,j;
  cin>>n;
  char *c=new char[n];
  int *b=new int[n];
  cin>>c[0];
  if(c[0]=='B')
    count++;
  for(i=1,j=0;i<n;i++){
    cin>>c[i];
    if(c[i]=='B'){
      count++;
    }
    else{
      if(c[i-1]=='B'){
        b[j++]=count;
      }
      count=0;
    }
  }
  if(c[n-1]=='B')
  b[j++]=count;
  b[j]=0;
  cout<<j<<endl;
  if(j)
  for(int i=0;b[i];i++)
  cout<<b[i]<<' ';
  return 0;
}