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
    vi a(n),b(n);
    forn(n) {
        cin>>a[i];
        b[i] = a[i];
    }
    sort(all(b));
    unm<int ,int> um;
    forn(n) um[b[i]] = i;
    int l = -1, r = -1;
    forn(n) if(um[a[i]]!=i) {
        l = i;
        break;
    }
    forR(n) if(um[a[i]]!=i) {
        r = i;
        break;
    }
    if (l==-1 or r==-1) {
        cout<<"yes\n";
        cout<<1<<" "<<1<<endl;
    } else {
        reverse(a.begin()+l,a.begin()+r+1);
        forn(n) {
            if(um[a[i]]!=i) {
                cout<<"no"<<endl;
                return;
            }
        }
        cout<<"yes\n";
        cout<<l+1<<" "<<r+1<<endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin>>t;
    while(t--) {
        // cout<<solve()<<endl;
        solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}