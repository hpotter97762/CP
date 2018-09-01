#include<iostream>
#include <list>
#include<cstring>
using namespace std;
list<int>*adj;
int *visited;
bool *gov;
int siz;

void dfs(int i,bool &flag){
    siz++;
    visited[i]=true;
    if(gov[i]==true)
        flag=true;
    list<int>::iterator it;
    for(it=adj[i].begin();it!=adj[i].end();it++){
        if(visited[*it]==false){
            dfs(*it,flag);
        }
    }
}

int main() {
    int v,e,k,a,b;
    cin>>v>>e>>k;
    adj=new list<int>[v];
    visited=new int[v];
    gov=new bool[v];
    for(int i=0;i<v;i++)
        gov[i]=false,visited[i]=false;
    //memset(gov,false,v);
    //memset(visited,false,v);
    for(int i=0;i<k;i++){
        cin>>a;
        gov[a-1]=true;
    }
    for(int i=0;i<e;i++){
        cin>>a>>b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int mx=0,fcount=0,edge=0;
    for(int i=0;i<v;i++){
        if(visited[i]==false){
            bool flag=false;
            siz=0;
            dfs(i,flag);
            if(flag==true){
                if(mx<siz)
                    mx=siz;
                edge=edge+(siz*(siz-1)/2);
            }
            else{
                fcount+=siz;
            }
        }
    }
    edge+=(fcount*mx);
    edge+=(fcount*(fcount-1)/2);
    cout<<(edge-e)<<'\n';
    return 0;
}