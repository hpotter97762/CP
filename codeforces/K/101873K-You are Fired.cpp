/*
 * Deleted code is debugged code :)
 */
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define vpp vector<pair<ll,ll>>
#define pp pair<ll,ll>
#define mp make_pair
#define PI acos(-1.0)
#define all(v) v.begin(),v.end()
#define pb push_back
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FREV(i,a,b) for(i=a;i>=b;i--)
#define FORI(a) for(auto it=a.begin();it!=a.end();it++)
#define READ(a,i,n) FOR(i,0,n) {cin>>a[i];}
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sll(n) scanf("%lld", &n)
#define sll2(n,m) scanf("%lld %lld", &n, &m)
#define si(n) scanf(" %d", &n)
#define ss(n) scanf(" %s", n)
#define sc(n) scanf(" %c", &n)
#define INF 1000000000000007
#define MOD 1000000007
#define RANDOM_SEED chrono::high_resolution_clock::now().time_since_epoch().count()

using namespace std;

template<typename T>
void prn(T first) {
    cout << first << "\n";
}

template<typename T, typename... Args>
void prn(T first, Args... args) {
    cout << first << " ";
    prn(args...);
}

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<
// ll,
// null_type, // insert type for map
// less<ll>,
// rb_tree_tag,
// tree_order_statistics_node_update> // required if using order_of_key(), find_by_order()
// ordered_set;

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

vector<pair<ll,string>> emps;

int main() {
    sync;
    ll i,j,t,n,d,k;
    cin >> n >> d >> k;
    emps.resize(n);
    FOR(i,0,n) {
        cin >> emps[i].second >> emps[i].first;
    }
    sort(all(emps), [](pair<ll,string> a, pair<ll,string> b) {return a.first > b.first;});
    i = 0;
    ll sum = 0;
    while (i < k) {
        sum += emps[i].first;
        if (sum >= d) {
            break;
        }
        i++;
    }
    if (i >= k) {
        cout << "impossible";
    }
    else {
        cout << i+1 << "\n";
        FOR(j,0,i+1) {
            cout << emps[j].second << ", YOU ARE FIRED!\n";
        }
    }
    return 0;
}
