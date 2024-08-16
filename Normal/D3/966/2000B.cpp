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
    vi arr(n);
    uns<int> availableSeats;
    uns<int> seated;
    // fore(1,n+1) availableSeats.insert(i);
    bool ans = true;
    // cout<<"\nlskdjf "<<n<<endl;
    forn(n) {
        int a; cin>>a;
        a = a-1;
        // cout<<a<<" ";
        // cout<<i<<endl;
        if(seated.size()==0) {
            if(a-1>-1) arr[a-1] = 1;
            if(a+1<n) arr[a+1] = 1;
            seated.insert(a);
        } else {
            if(seated.count(a)>0) {
                ans = false;
            } else if(arr[a]==1) {
                seated.insert(a);
                if(a-1>-1) arr[a-1] = 1;
                if(a+1<n) arr[a+1] = 1;
            } else {
                ans = false;
            }
        }
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    // cout<<t<<endl;
    while(t--) {
        bool ans = solve();
        // cout<<ans<<endl;
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}