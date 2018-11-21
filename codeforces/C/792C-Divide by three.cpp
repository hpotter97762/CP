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
const int mod1=1e9+7;

inline ll rl(){
    ll res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){res=(res<<1)+(res<<3)+c-48;c=getchar();}
    return neg?-res:res;
}

inline void read(string &s){
    char c=getchar();
    while(c!='\n'){
        s+=c;
        c=getchar();
    }
}
vi num;
int sum=0;
vector<vi>mod(2);

void print(vi & a){
    int i=0;
    for(;i<a.size();++i)
        if(a[i])
            break;
    if(i==a.size())
        cout<<0;
    for(;i<a.size();++i)
        cout<<a[i];
    cout<<'\n';
}

int f(ll a){
    if(mod[a].size()>=2)
        return 2;
    return 1e8;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
    char c=getchar();
    while(c!='\n'){
        num.push_back(c-'0');
        c=getchar();
        sum+=num.back();
        if(num.back()%3)
            mod[num.back()%3-1].push_back(num.size()-1);
    }
    int cnt;
    int i;
    for(i=1;i<num.size()&&!num[i];++i);
    cnt=i-1;
    if(sum%3==0){
        print(num);
        return 0;
    }
    if((mod[sum%3-1].size()==0&&mod[sum%3%2].size()<2)||((mod[sum%3-1].size()==1&&num.size()==1)||(mod[sum%3%2].size()==2&&num.size()==2))){
        cout<<-1<<'\n';
        return 0;
    }
    if(mod[sum%3-1].size()>1||(mod[sum%3-1].size()==1&&mod[sum%3-1][0]>0)){
        num.erase(num.begin()+mod[sum%3-1].back());
        print(num);
    }
    else if(mod[sum%3-1].size()==1){
        if(cnt+1>f((sum%3)%2)){
            num.erase(num.begin()+mod[sum%3%2].back());
            mod[sum%3%2].pop_back();
            num.erase(num.begin()+mod[sum%3%2].back());
            print(num);
        }
        else{
            num.erase(num.begin()+mod[sum%3-1][0]);
            print(num);
        }
    }
    else{
        num.erase(num.begin()+mod[sum%3%2].back());
        mod[sum%3%2].pop_back();
        num.erase(num.begin()+mod[sum%3%2].back());
        print(num);
    }
	return 0;
}