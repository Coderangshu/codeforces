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

bool customSort(const pair<int,int> &a, const pair<int,int> &b) {
    if(a.x!=b.x) return (a.x>b.x);
    return (a.y<b.y);
}

auto solve() {
    int n,k;cin>>n>>k;
    vector<pii> v;
    forn(n) {
        int p,t;cin>>p>>t;
        v.pb(mp(p,t));
    }
    sort(all(v),customSort);
    // forA(v) {
    //     cout<<i.x<<" "<<i.y<<endl;
    // }

    int curRank = 0, curRankShared = 0, i = 0;
    while(i<sz(v)) {
        curRank++;
        curRankShared = 0;
        int curP = v[i].x, curT = v[i].y;
        // cout<<i<<"   dsfldkjfadlkfj   "<<curRankShared<<" "<<curP<<" "<<curT<<endl;
        while(i+1<sz(v) and v[i+1].x==curP and v[i+1].y==curT) {
            // cout<<i<<"    df    "<<curRankShared<<endl;
            i++;
            curRankShared++;
            // cout<<i<<endl;
        }
        // cout<<"curRank "<<curRank<<" currRankShared "<<curRankShared<<endl;
        if(curRank<=k and k<=curRank+curRankShared) return curRankShared+1;
        curRank += curRankShared;
        i++;
        // cout<<i<<"ldkjsf"<<endl;
    }

    return curRankShared;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--)
        cout<<solve()<<endl;
}