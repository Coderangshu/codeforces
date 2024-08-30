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
#define for(i,n) for(int i = 0; i < int(n); i++)
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
    for(i,n) cin>>arr[i];
    return arr;
}

string getStr() {
    string strIp;
    getline(cin,strIp);
    return strIp;
}

class Compare {
public:
    bool operator()(pii a, pii b)
    {
        if(min(a.x,a.y)>min(b.x,b.y)) return true;
        return false;
    }
};

auto solve() {
    int n,k;cin>>n>>k;
    vi aa,ba;
    for(i,n) {
        int a,b; cin>>a>>b;
        aa.pb(a); ba.pb(b);
    }
    vector<vi> dp(n+1,vi(k+1,1e9));
    for(i,n+1) dp[i][0] = 0;
    for(ithRectangle,n) {
        int a = aa[ithRectangle], b = ba[ithRectangle], cost = 0, apb = a+b;
        for(pnts2Add,apb+1) {
            for(diff,k-pnts2Add+1) {
                int totMarks = pnts2Add+diff;
                dp[ithRectangle+1][totMarks] = min(dp[ithRectangle+1][totMarks],dp[ithRectangle][diff]+cost);
            }
            if(pnts2Add<apb) {
                if(a>b) {
                    a--;
                    cost += b;
                } else {
                    b--;
                    cost += a;
                }
            }
        }
    }
    
    return (dp[n][k]==1e9)?-1:dp[n][k];
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--) {
        cout<<solve()<<endl;
        // solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}