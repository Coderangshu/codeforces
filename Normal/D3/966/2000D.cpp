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
    int n;cin>>n;
    vi a(n);
    vector<char> v(n);
    forn(n) cin>>a[i];
    forn(n) cin>>v[i];

    vi prefix(n+1);
    int sum = 0;
    forn(n) {
        sum += a[i];
        // cout<<a[i]<<" "<<sum<<endl;
        prefix[i+1] = sum;
    }
    // forA(prefix) cout<<i<<" ";
    // cout<<endl;

    int l = 1, r = n;
    int ans = 0;
    while(l<r) {
        if(v[l-1]=='L' and v[r-1]=='R'){
            ans += prefix[r]-prefix[l-1];
            l++;
            r--;
        }
        if(v[l-1]=='R') l++;
        if(v[r-1]=='L') r--;
    }

    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--)
        cout<<solve()<<endl;
}