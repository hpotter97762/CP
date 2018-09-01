#include<iostream>
using namespace std;

int main(){
int i=0,r=-1,b=-1,g=-1,y=-1;
int ans[4]={0};
char s[100];
cin>>s;
while(s[i]){
if(s[i]=='R'){
r=i%4;
}
else if(s[i]=='B'){
b=i%4;
}
else if(s[i]=='G'){
g=i%4;
}
else if(s[i]=='Y'){
y=i%4;
}
if(s[i]=='!'){
ans[i%4]++;
if(b!=i%4&&g!=i%4&&y!=i%4)
r=i%4;
if(r!=i%4&&g!=i%4&&y!=i%4)
b=i%4;
if(b!=i%4&&r!=i%4&&y!=i%4)
g=i%4;
if(b!=i%4&&g!=i%4&&r!=i%4)
y=i%4;
}
i++;
}
cout<<ans[r]<<" "<<ans[b]<<" "<<ans[y]<<" "<<ans[g];
return 0;
}