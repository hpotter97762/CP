#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

struct shirt{
	int price,fcol,bcol;
	bool sold;
};

bool cmp(shirt a,shirt b){
	return a.price>b.price;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	shirt s[n];
	for(int i=0;i<n;i++){
		cin>>s[i].price;
		s[i].sold=false;
	}
	for(int i=0;i<n;i++)
		cin>>s[i].fcol;
	for(int i=0;i<n;i++)
		cin>>s[i].bcol;
	int m;
	cin>>m;
	int b[m],buy[m];
	for(int i=0;i<m;i++)
		cin>>b[i];
	sort(s,s+n,cmp);
	stack <shirt*> st[4];
	for(int i=0;i<n;i++){
		st[s[i].fcol].push(s+i);
		if(s[i].fcol!=s[i].bcol)
			st[s[i].bcol].push(s+i);
	}
	for(int i=0;i<m;i++){
		for(int j=1;j<4;j++){
			if(st[j].empty())
				continue;
			while(st[j].top()->sold==true){
				st[j].pop();
				if(st[j].empty())
					break;
			}
		}
		if(st[b[i]].empty()){
			buy[i]=-1;
			continue;
		}
		buy[i]=st[b[i]].top()->price;
		st[b[i]].top()->sold=true;
		st[b[i]].pop();
	}
	for(int i=0;i<m;++i)
		cout<<buy[i]<<" ";
	return 0;
}