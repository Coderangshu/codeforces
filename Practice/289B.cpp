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
    int n,m,d;cin>>n>>m>>d;
    vi v;
    forn(n) forn(m) {
        int a; cin>>a;
        v.pb(a);
    }
    int mod = v[0]%d;
    forA(v) if(i%d!=mod) return int(-1);
    sort(all(v));
    // forA(v) cout<<i<<" ";
    // cout<<endl;
    int median = v[sz(v)/2];
    int ans = 0;
    forA(v) ans += abs(i-median)/d;
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--)
        cout<<solve()<<endl;
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}