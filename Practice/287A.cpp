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
    vector<string> v(4);
    forn(4) {
        cin>>v[i];
    }
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            int h = 0, d = 0;
            for(int k=0;k<2;k++) {
                for(int l=0;l<2;l++) {
                    if(v[i+k][j+l]=='#') h++;
                    if(v[i+k][j+l]=='.') d++;
                }
            }
            if((d==3 and h==1) or (d==1 and h==3)) return "YES";
            else if(d==4 or h==4) return "YES";
        }
    }
    return "NO";
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--)
        cout<<solve()<<endl;
}