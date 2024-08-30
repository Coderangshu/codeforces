#include<bits/stdc++.h>
using namespace std;

#define int ll
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(n) for(int i = 0; i < int(n); i++)
#define forR(n) for(int i = n-1; i > -1; i--)
#define fore(l, r) for(int i = int(l); i < int(r); i++)
#define forA(arr) for(auto i:arr)
#define unm unordered_map
#define uns unordered_set

using ll = long long;
typedef long double ld;
using pii = pair<int, int>;
typedef vector<long long> vi;

vector<int> getInts(int n) {
    vi arr(n);
    forn(n) cin>>arr[i];
    return arr;
}

string getStr() {
    string strIp;
    getline(cin,strIp);
    return strIp;
}

auto solve() {
    int n,m; cin>>n>>m;
    vi v(n); forn(n) cin>>v[i];
    vi uniqueCnt(n);
    uns<int> us;
    int uc = 0;
    forR(n) {
        if(us.count(v[i])==0) {
            uc++;
            us.insert(v[i]);
        }
        uniqueCnt[i] = uc;
    }
    // forA(v) cout<<i<<" ";
    // cout<<endl;
    // forA(uniqueCnt) cout<<i<<" ";
    // cout<<endl;
    while(m--) {
        int l;cin>>l;
        cout<<uniqueCnt[--l]<<endl;
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--)
        // cout<<solve()<<endl;
        solve();
}