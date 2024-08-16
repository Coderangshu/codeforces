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
vi a;
vector<vi> children;
int inf = 2e5+20;

bool dfs(int ind, int target) {
    if(a[ind]<target) {
        if(children[ind].empty()) return false;
        int newTarget = target-a[ind];
        // a[ind] is not root then this node also needs to be atleast target
        // as per the dfs's definition, thus newTarget will also need to contain
        // target value in it
        if(ind) newTarget += target;
        // also setting some upper limit of newTarget as when target becomes very
        // large it is impossible to cover up using the subtree nodes
        newTarget = min(newTarget,inf);
        forA(children[ind]) {
            if(!dfs(i,newTarget)) return false;
        }
    }
    return true;
}

auto solve() {
    int n; cin>>n;
    a.assign(n,0);
    children.assign(n,vi(0));
    forn(n) {
        int ai; cin>>a[i];
    }
    fore(1,n) {
        int pi; cin>>pi;
        children[pi-1].pb(i);
    }

    forn(n) {
        cout<<i<<": ";
        forA(children[i]) cout<<i<<" ";
        cout<<endl;
    }

    int lo = 0, hi = inf;
    while(hi-lo>1) {
        int mid = (1ll+lo+hi)/2;
        if(dfs(0,mid)) lo = mid;
        else hi = mid;
    }
    return lo;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--)
        cout<<solve()<<endl;
}