#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int bf[n],af[n];
    int flag=0;
    for(int i=0;i<n;++i){
        cin>>bf[i]>>af[i];
        if(bf[i]!=af[i])
            flag=1;
    }
    if (flag==1){
        cout<<"rated\n";
        return 0;
    }
    for(int i=1;i<n;i++){
        if(bf[i]>bf[i-1]){
            cout<<"unrated\n";
            return 0;
        }
    }
    cout<<"maybe\n";
    return 0;
}