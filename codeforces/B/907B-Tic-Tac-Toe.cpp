#include<bits/stdc++.h>
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
#define e 2.7182818284590452353602874713526624977572

typedef long long int ll;
typedef long double ld;
typedef std::vector<ll> vi;
typedef std::vector<bool> vb;
typedef std::vector<char> vc;
typedef std::pair<ll,ll> pii;
typedef std::vector<pii> vii;

using namespace std;
const int mod=1e9+7;

inline ll rl(){
    ll res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}

inline void read(string &s){
    s="";
    char c=getchar();
    while(c!='\n'){
        s+=c;
        c=getchar();
    }
}

int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	vector<vc> a(9);
	for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            char c;
            cin>>c;
            a[i].push_back(c);
        }
    }
    ll x=rl()-1,y=rl()-1;
    int i ;
    for(i=3*(x%3);i<3*(x%3+1);++i)
        for(int j=3*(y%3);j<3*(y%3+1);++j){
            if(a[i][j]=='.')
                goto exit;
        }
    exit:;
    if(i==3*(x%3+1)){
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(a[i][j]=='.')
                    cout<<'!';
                else
                    cout<<a[i][j];
                if(j%3==2&&j!=8)
                    cout<<' ';
            }
            cout<<'\n';
            if(i%3==2&&i!=8)
                cout<<'\n';
        }
    }
    else{
        for(i=3*(x%3);i<3*(x%3+1);++i)
            for(int j=3*(y%3);j<3*(y%3+1);++j){
                if(a[i][j]=='.')
                    a[i][j]='!';
            }
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                cout<<a[i][j];
                if(j%3==2&&j!=8)
                    cout<<' ';
            }
            cout<<'\n';
            if(i%3==2&&i!=8)
                cout<<'\n';
        }
    }
	return 0;
}