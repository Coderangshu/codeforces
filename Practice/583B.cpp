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
#define forl(i,n) for(int i = 0; i < int(n); i++)
#define forr(i,n) for(int i = n-1; i > -1; i--)
#define fore(l, r) for(int i = int(l); i < int(r); i++)
#define fora(v,arr) for(auto v:arr)
#define unm unordered_map
#define uns unordered_set

using ll = long long;
typedef long double ld;
using pii = pair<int, int>;
typedef vector<long long> vi;

vector<int> getInts(int n) {
    vi arr(n);
    forl(i,n) cin>>arr[i];
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
    forl(i,n) cin>>a[i];
    int ans = 0, hint = 0;
    while(true) {
        forl(i,n) if(a[i]<=hint) a[i] = n+1, hint++;
        if(hint==n) break;
        ans++;
        forr(i,n) if(a[i]<=hint) a[i] = n+1, hint++;
        if(hint==n) break;
        ans++;
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--) {
        cout<<solve()<<endl;
        // solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}