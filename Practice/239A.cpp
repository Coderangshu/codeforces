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
#define forr(l, r) for(int i = int(l); i < int(r); i++)
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

auto solve() {
    vector<li> ips = getInts(3);
    li y = ips[0], k = ips[1], n = ips[2];
    vector<li> ans;
    li num = y;
    num = (num/k+1)*k;
    if(num<=n) ans.pb(num-y);
    while(num<=n) {
        num += k;
        if(num<=n) ans.pb(num-y);
    }

    return ans;
}

int main() {
    // li t;
    // cin>>t;
    // while(t--)
        auto ans = solve();
        if(sz(ans)==0) {
            cout<<-1<<endl;
        } else {
            forA(ans) cout<<i<<" ";
            cout<<endl;
        }
    return 0;
}