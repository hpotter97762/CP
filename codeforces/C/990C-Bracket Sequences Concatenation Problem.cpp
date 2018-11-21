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
const ll mod=1e9+7;

void sort1(vi &a){
    ll n=a.size();
    sort(a.begin(),a.end());
    vi b;
    b.push_back(a[0]);
    for(ll i=1;i<n;++i){
        if(a[i]!=a[i-1])
            b.push_back(a[i]);
    }
    a=b;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    string s;
    vi left(3*1e5+2,0),right(3*1e5+2,0);
    vc st;
    for(ll i=0;i<n;++i){
        st.resize(0);
        cin>>s;
        st.push_back(s[0]);
        for(ll j=1;j<s.size();++j){
            if(s[j]==')'){
                if(!st.empty()&&st.back()=='(')
                    st.pop_back();
                else
                    st.push_back(s[j]);
            }
            else
                st.push_back(s[j]);
        }
        if(st.empty())
            left[0]++,right[0]++;
        else if(st.back()=='('){
            if(st[0]=='(')
                left[st.size()]++;
        }
        else
            right[st.size()]++;
    }
    // for(ll i=0;i<20;++i)
    //     cout<<left[i]<<' '<<right[i]<<'\n';
    ll ans=0;
    for(ll i=0;i<right.size();++i){
        ans+=left[i]*right[i];
    }
    cout<<ans<<'\n';
    return 0;
}