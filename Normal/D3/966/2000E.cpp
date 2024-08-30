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
#define fori(n) for(int i = 0; i < int(n); i++)
#define forj(n) for(int j = 0; j < int(n); j++)
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
    fori(n) cin>>arr[i];
    return arr;
}

string getStr() {
    string strIp;
    getline(cin,strIp);
    return strIp;
}

auto solve() {
    int n,m,k;
    cin>>n>>m>>k;
    int w; cin>>w;
    vi a(w);
    vi eachGridContribution;
    fori(w) cin>>a[i];
    fori(n) {
        forj(m) {
            int lowerBoundy = max(0ll,j-k+1), upperBoundy = min(m-k,j);
            int lowerBoundx = max(0ll,i-k+1), upperBoundx = min(n-k,i);
            int diffY = upperBoundy-lowerBoundy+1, diffX = upperBoundx-lowerBoundx+1;
            eachGridContribution.pb(diffY*diffX);
        }
    }
    sort(all(eachGridContribution),greater<int>());
    sort(all(a),greater<int>());
    int ans = 0;
    fori(w) {
        ans += a[i]*eachGridContribution[i];
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--)
        cout<<solve()<<endl;
}