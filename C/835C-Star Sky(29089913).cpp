#include<bits/stdc++.h>
#define ll unsigned long long int
#define vi vector<int>
using namespace std;

int main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    int n,z,c;
    cin>>n>>z>>c;
    ++c;
    int p,q,r;
    vector<vector<vi>>op(101,vector<vi>(101,vi(c,0)));
    for(int i=0;i<n;++i){
        cin>>p>>q>>r;
        for(int j=0;j<c;++j)
            op[p][q][j]+=(r+j)%c;
    }
    for(int i=0;i<101;++i){
        for(int j=1;j<101;++j){
            for(int k=0;k<c;++k){
                op[i][j][k]+=op[i][j-1][k];
            }
        }
    }
    int t,x1,y1,x2,y2;
    while(z--){
        cin>>t>>x1>>y1>>x2>>y2;
        t%=c;
        int ans1=0;
        for(int ii=x1;ii<=x2;++ii){
            ans1+=op[ii][y2][t]-op[ii][y1-1][t];
        }
        cout<<ans1<<'\n';
    }
    return 0;
}