#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forn(n) for(int i = 0; i < int(n); i++) 
#define fore(l, r) for(int i = int(l); i < int(r); i++)
#define forA(arr) for(auto i:arr)
#define unm unordered_map

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

vector<li> getInts(li n) {
    vector<li> arr(n);
    forn(n) cin>>arr[i];
    return arr;
}

string getStr() {
    string strIp;
    getline(cin,strIp);
    return strIp;
}

void solve() {
    li n, a;
    cin>>n;
    vector<int> v(n);
    forn(n) cin>>v[i];
    fore(1,n) cout<<v[i]<<" ";
    cout<<v[0]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);
    
    li t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}