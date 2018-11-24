#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,c;
 
bool ans(int *a,int k){
    int p=1,prev=a[0];
    for(int i=1;i<n;){
        while(a[i]-prev<k&&i<n)++i;
        if(i==n)
            break;
        p++;
        prev=a[i];
	}
	if(p>=c)
        return true;
    return false;
}
 
int solve(int *a){
    int beg=1,last=a[n-1]-a[0]+1;
    while(beg<=last){
        int mid=beg+(last-beg)/2;
        if(ans(a,mid)==0){
            last=mid-1;
        }
        else{
            if(ans(a,mid+1)==1)
                beg=mid+1;
            else
                return mid;
        }
	}
	return last;
}
 
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>c;
		int a[n];
		for(int i=0;i<n;++i){
            cin>>a[i];
		}
		sort(a,a+n);
		cout<<solve(a)<<'\n';
	}
	return 0;
}
