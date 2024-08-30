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
    string ht,at; cin>>ht>>at;
    int n;cin>>n;
    vector<vi> a(2,vi (100));
    while (n--)
    {
        int t,pn;
        char hoa, card;
        cin>>t>>hoa>>pn>>card;
        if(hoa=='h') {
            if(a[0][pn]==-1) continue;
            if(card=='r') cout<<ht<<" "<<pn<<" "<<t<<endl, a[0][pn] = -1;
            else {
                a[0][pn]++;
                if(a[0][pn]>=2) cout<<ht<<" "<<pn<<" "<<t<<endl, a[0][pn] = -1;
            }
        } else {
            if(a[1][pn]==-1) continue;
            if(card=='r') cout<<at<<" "<<pn<<" "<<t<<endl, a[1][pn] = -1;
            else {
                a[1][pn]++;
                if(a[1][pn]>=2) cout<<at<<" "<<pn<<" "<<t<<endl, a[1][pn] = -1;
            }
        }
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

