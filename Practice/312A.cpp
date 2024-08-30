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
#define fore(l, r) for(int i = int(l); i <= int(r); i++)
#define fora(v,arr) for(auto v:arr)
#define unm unordered_map
#define uns unordered_set
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN

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
    char s[101];
    cin.getline(s, 100, '\n');
    cout<<s<<endl;
    char *token = strtok(s," ");
    vector<string> vs;
    while(token) {
        vs.pb(token);
        token = strtok(NULL, " ");
    }
    // string f = vs[0], l = vs[sz(vs)-1];
    // cout<<f<<" "<<l<<endl;
    // if((f!="lala" and l!="miao") or (f=="lala" and l=="miao")) return "OMG>.< I don't know!\n";
    // else if(f=="lala") return "Freda's\n";
    // else return "Rainbow's\n";
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin>>t;
    cout<<t<<endl;
    while(t--) {
        // cout<<solve()<<endl;
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

