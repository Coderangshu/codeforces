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
    int n; cin>>n;
    vi v(n);forn(n) cin>>v[i];
    vi vsum(n+1);
    int sum = 0;
    forn(n+1) {
        vsum[i] = sum;
        if(i<n) sum += v[i];
    }
    sort(all(v));
    vi vssum(n+1);
    sum = 0;
    forn(n+1) {
        vssum[i] = sum;
        if(i<n) sum += v[i];
    }
    int m; cin>>m;
    while(m--) {
        int t,l,r; cin>>t>>l>>r;
        if(t==1) cout<<vsum[r]-vsum[l-1]<<endl;
        else cout<<vssum[r]-vssum[l-1]<<endl;
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