#include<vector>
#include<iostream>
using namespace std;

int main(){
string a;
cin>>a;
int n=a.size();
int num[26];
for(int i=0;i<26;i++)
	num[i]=-1;
for(int i=0;i<n;++i){
	num[a[i]-'a']=i;
}
vector<char> s;
int j=0;
for(int i=0;i<26&&j<n;i++){
	while(!(s.empty())&&s.back()<=i+'a'){
		cout<<s.back(); //print
		s.pop_back();
	}
	while(j<=num[i]){
		if(a[j]!=i+'a')
			s.push_back(a[j]);
		else
			cout<<a[j]; //print
		j++;
	}
}
while(!s.empty()){
	cout<<s.back();  //print
	s.pop_back();
}
cout<<endl;
return 0;
}