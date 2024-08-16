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

vi v;
unm<int,int> um;

int recursion(int lengthLeft) {
    if(lengthLeft==0) return 0;
    if(um.count(lengthLeft)>0) return um[lengthLeft];
    int ans = INT_MIN;
    forA(v) if(lengthLeft>=i) ans = max(ans,recursion(lengthLeft-i)+1);
    return um[lengthLeft] = ans;
}


auto solve() {
    int n,a,b,c; cin>>n>>a>>b>>c;
    um.clear();
    v = {a,b,c};
    // forA(v) cout<<i<<" ";
    // cout<<endl;
    return recursion(n);
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--)
        cout<<solve()<<endl;
}