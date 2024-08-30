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
    int n,m;cin>>n>>m;
    int md = (m+1)/2, md1 = (m+1)-md;
    // int turnEven = 0;
    // cout<<n<<" "<<m<<" "<<md<<endl;
    while(n>0) {
        cout<<md<<endl;
        n--;
        if(n==0) return;
        if(md!=md1) {
            cout<<md1<<endl;
            n--;
            if(n==0) return;
        }
        md--;md1++;
        if(md==0) {
            md = (m+1)/2;
            md1 = (m+1)-md;
        }
    }
    return;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--) {
        // cout<<solve()<<endl;
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}