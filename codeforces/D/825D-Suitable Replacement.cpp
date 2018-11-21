#include<bits/stdc++.h>
#define ll long long int
#define vi vector<ll,ll>
#define vb vector<bool>
#define vc vector<char>
#define mp make_pair
#define pint pair<ll,ll>
#define pi 3.141592653589793238462643383279502884197
#define mod 1000000007
//#define e 2.718281828459045235360287471352662497757

using namespace std;

int read_int(){
    int res=0,neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){
        res=(res<<1)+(res<<3)+c-48;
        c=getchar();
    }
    return neg?-res:res;
}

ll read_ll(){
    ll res=0;
    int neg=0;
    char c=getchar();
    while((c<'0'||c>'9')&&c!='-')c=getchar();
    if(c=='-')neg=1,c=getchar();
    while(c>='0'&&c<='9'){
        res=(res<<1)+(res<<3)+c-48;
        c=getchar();
    }
    return neg?-res:res;
}

void copy(int *a,int *b)
{
    for(int i=0;i<26;++i)
        a[i]+=b[i];
}

void print(int *sa,int *ta)
{
	for(int i=0;i<26;++i)
        cout<<sa[i]<<" ";
    cout<<'\n';
	for(int i=0;i<26;++i)
        cout<<ta[i]<<' ';
    cout<<'\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
	string s,t;
	cin>>s;
	cin>>t;
	int sa[26],ta[26];
	for(int i=0;i<26;++i)
		sa[i]=0,ta[i]=0;
	sa[26]=0;
	for(int i=0;i<s.size();++i){
		sa[s[i]-97]++;
	}
	for(int i=0;i<t.size();++i){
		ta[t[i]-97]++;
	}
	int j=0;
	for(int i=0;i<26;++i){
		sa[i]=ta[i]-sa[i];
	}
	//print(sa,ta);
	for(int i=0;i<s.size();++i){
		if(isalpha(s[i]))
			cout<<s[i];
		else{
			while(sa[j]<=0&&j<26)++j;
			if(j==26){
				j=0;
				copy(sa,ta);
				--i;
				continue;
			}
			cout<<(char)(j+'a');
			sa[j]--;;
		}
	}
	return 0;
}