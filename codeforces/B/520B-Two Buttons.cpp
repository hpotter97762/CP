#include<iostream>
#include<queue>
#include<cstring>
#define LP 30000
using namespace std;
int n,m;
bool a[LP];

int bfs(){
    a[n]=true;
    queue<int> q;
    int j,i=0;
    q.push(n);
    q.push(i--);
    while(!(q.empty())){
        j=q.front();
        q.pop();
        if(!a[j-1]&&j>1){
            q.push(j-1);
            a[j-1]=true;
        }
        if(j<m){
            if(a[2*j]==0){
                q.push(2*j);
                a[2*j]=true;
            }
        }
        if(j-1==m||2*j==m)
            break;
        if(q.front()<=0){
            q.push(i--);
            q.pop();
        }
    }
    return (-i);
}

int main(){
    int k;
    cin>>n>>m;
    if(m<=n){
        cout<<n-m;
        return 0;
    }
    memset(a,false,LP);
        k=bfs();
    cout<<k;
    return 0;
}