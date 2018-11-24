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
 
void print(vc &a){
    for(int  i=0;i<a.size();++i)
        cout<<a[i];
    cout<<'\n';
}
 
int main(){
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    string s;
    while(t--){
        cin>>s;
        vc st;
        char ans[500];
        ll z=0;
        st.push_back('(');
        for(int i=0;i<s.size();++i){
            if(isalpha(s[i]))
                ans[z++]=s[i];
            else if(s[i]!=')'){
                st.push_back(s[i]);
            }
            else{
                while(st.back()!='('){
                    ans[z++]=st.back();
                    st.pop_back();
                }
                st.pop_back();
            }
            // print(st);
        }
        while(!st.empty()){
            if(st.back()!='(')
                ans[z++]=st.back();
            st.pop_back();
        }
        ans[z]=0;
        cout<<ans<<'\n';
    }
    return 0;
}
