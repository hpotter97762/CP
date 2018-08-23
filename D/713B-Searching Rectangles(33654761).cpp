#include<bits/stdc++.h>
#define fs first
#define sc second
#define pi 3.141592653589793238462643383279502884197
//#define e 2.7182818284590452353602874713526624977572

typedef long long int ll;
typedef long double ld;
typedef std::vector<ll> vi;
typedef std::vector<bool> vb;
typedef std::vector<char> vc;
typedef std::pair<ll,ll> pii;
typedef std::vector<pii> vii;

using namespace std;
const int mod=1e9+7;

vi ans;
ll rb,lb,tb,bb,n;
pii h1,h2,v1,v2;

void findb(){
    ll an,t=tb,l=lb,r=rb,st=1,en=tb;
    while(st<en){
        ll m=en-(en-st)/2;
        cout<<'?'<<' '<<m<<' '<<l<<' '<<t<<' '<<r<<'\n';
        fflush(stdout);
        cin>>an;
        if(an==2)
            st=m;
        else
            en=m-1;
    }
    bb=en;
}

void findt(){
    ll an,b=1,l=lb,r=rb,st=1,en=n;
    while(st<en){
        ll m=(en+st)/2;
        cout<<'?'<<' '<<b<<' '<<l<<' '<<m<<' '<<r<<'\n';
        fflush(stdout);
        cin>>an;
        if(an==2)
            en=m;
        else
            st=m+1;
    }
    tb=en;
    findb();
}

void findl(){
    ll an,t=n,b=1,r=rb,st=1,en=rb;
    while(st<en){
        ll m=en-(en-st)/2;
        cout<<'?'<<' '<<b<<' '<<m<<' '<<t<<' '<<r<<'\n';
        fflush(stdout);
        cin>>an;
        if(an==2)
            st=m;
        else
            en=m-1;
    }
    lb=en;
    findt();
}

void findr(){
    ll an,t=n,b=1,l=1,st=1,en=n;
    while(st<en){
        ll m=(st+en)/2;
        cout<<'?'<<' '<<b<<' '<<l<<' '<<t<<' '<<m<<'\n';
        fflush(stdout);
        cin>>an;
        if(an==2)
            en=m;
        else
            st=m+1;
    }
    rb=en;
    findl();
}

void findv2(){
    ll an,st=bb,en=tb;
    while(st<en){
        ll m=en-(en-st)/2;
        cout<<'?'<<' '<<m<<' '<<lb<<' '<<tb<<' '<<rb<<'\n';
        fflush(stdout);
        cin>>an;
        if(an==0)
            en=m-1;
        else
            st=m;
    }
    v2={en,tb};
}

void findv1(){
    ll an,st=bb,en=tb;
    while(st<en){
        ll m=(st+en)/2;
        cout<<'?'<<' '<<bb<<' '<<lb<<' '<<m<<' '<<rb<<'\n';
        fflush(stdout);
        cin>>an;
        if(an==0)
            st=m+1;
        else
            en=m;
    }
    v1={bb,en};
    findv2();
}

void findh2(){
    ll an,st=lb,en=rb;
    while(st<en){
        ll m=en-(en-st)/2;
        cout<<'?'<<' '<<bb<<' '<<m<<' '<<tb<<' '<<rb<<'\n';
        fflush(stdout);
        cin>>an;
        if(an==0)
            en=m-1;
        else
            st=m;
    }
    h2={en,rb};
    findv1();
}

void findh1(){
    ll an,st=lb,en=rb;
    while(st<en){
        ll m=(st+en)/2;
        cout<<'?'<<' '<<bb<<' '<<lb<<' '<<tb<<' '<<m<<'\n';
        fflush(stdout);
        cin>>an;
        if(an==0)
            st=m+1;
        else
            en=m;
    }
    h1={lb,en};
    findh2();
}

int check(ll a, ll b,ll c,ll d){
    cout<<"? "<<a<<' '<<c<<' '<<b<<' '<<d<<'\n';
    fflush(stdout);
    ll an;
    cin>>an;
    return an;
}

int main(){
	cin>>n;
	findr();
	findh1();
	vi h,v;
	h.push_back(h1.fs),h.push_back(h1.sc),h.push_back(h2.fs),h.push_back(h2.sc);
	v.push_back(v1.fs),v.push_back(v1.sc),v.push_back(v2.fs),v.push_back(v2.sc);
	sort(h.begin(),h.end());
	sort(v.begin(),v.end());
	bool c1=check(v[1],v[2],1,n),c2=check(v[0],v[1],1,n),c3=check(1,n,h[1],h[2]),c4=check(1,n,h[0],h[1]);
    if(c2&&(!c1||v[1]!=v[2]))v1={v[0],v[1]},v2={v[2],v[3]};
    else if(c1)v1={v[1],v[2]},v2={v[0],v[3]};
    else v1={v[0],v[2]},v2={v[1],v[3]};
    if(c4&&(!c3||h[1]!=h[2]))h1={h[0],h[1]},h2={h[2],h[3]};
    else if(c3)h1={h[1],h[2]},h2={h[0],h[3]};
    else h1={h[0],h[2]},h2={h[1],h[3]};
    if(check(v1.fs,v1.sc,h1.fs,h1.sc)){ans.push_back(v1.fs);ans.push_back(h1.fs);ans.push_back(v1.sc);ans.push_back(h1.sc);}
    if(check(v1.fs,v1.sc,h2.fs,h2.sc)&&ans.empty()){ans.push_back(v1.fs);ans.push_back(h2.fs);ans.push_back(v1.sc);ans.push_back(h2.sc);}
    if(check(v2.fs,v2.sc,h2.fs,h2.sc)){ans.push_back(v2.fs);ans.push_back(h2.fs);ans.push_back(v2.sc);ans.push_back(h2.sc);}
    if(check(v2.fs,v2.sc,h1.fs,h1.sc)){ans.push_back(v2.fs);ans.push_back(h1.fs);ans.push_back(v2.sc);ans.push_back(h1.sc);}/*
    for(int i=0;i<ans.size();++i)
        cout<<ans[i]<<' ';
    cout<<'\n';*/
    if(ans.size()>8){
        if((ans[0]>=ans[4]&&ans[2]<=ans[6]&&ans[1]>=ans[5]&&ans[3]<=ans[7])||(ans[8]>=ans[4]&&ans[10]<=ans[6]&&ans[9]>=ans[5]&&ans[11]<=ans[7]))
            for(int i=0;i<4;++i)ans.erase(ans.begin()+4);
        else if((ans[4]>=ans[0]&&ans[6]<=ans[2]&&ans[5]>=ans[1]&&ans[7]<=ans[3])||(ans[8]>=ans[0]&&ans[10]<=ans[2]&&ans[9]>=ans[1]&&ans[11]<=ans[3]))
            for(int i=0;i<4;++i)ans.erase(ans.begin());
        else
            ans.resize(8);
    }
    cout<<'!'<<' ';
    for(int i=0;i<8;++i)
        cout<<ans[i]<<' ';
    cout<<'\n';/*
    cout<<h1.fs<<' '<<h1.sc<<' '<<h2.fs<<' '<<h2.sc<<' '<<v1.fs<<' '<<v1.sc<<' '<<v2.fs<<' '<<v2.sc<<'\n';
    for(int i=0;i<4;++i)
        cout<<h[i]<<' ';
    cout<<'\n';
    for(int i=0;i<4;++i)
        cout<<v[i]<<' ';
    cout<<'\n';
    cout<<lb<<' '<<rb<<' '<<bb<<' '<<tb<<'\n';*/
	return 0;
}
