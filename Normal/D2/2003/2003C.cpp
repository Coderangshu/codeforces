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
    int n;cin>>n;
    string s;cin>>s;
    unm<char,int> um;
    fori(n) um[s[i]] += 1;
    auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second; // For max heap (highest second value first)
        // return a.second > b.second; // For min heap (lowest second value first)
    };
    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
    for (const auto& pair : um) {
        pq.push(pair);
    }
    if(pq.size()==1) {
        string ans(n, pq.top().x);
        return ans;
    }
    string ans(n, ' ');
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int f = top.y;
        // cout << "Key: " << top.first << ", Value: " << top.second << endl;
        int i = 0;
        while(ans[i]!=' ') i++;
        while(f--) {
            ans[i] = top.x;
            i += 2;
        }
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--) {
        cout<<solve()<<endl;
        // solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}