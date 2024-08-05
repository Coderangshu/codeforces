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

vector<li> getInts() {
    string strIp;
    vector<li> inputArr;
    while (getline(cin, strIp, ' ')) inputArr.push_back(atol(strIp.c_str()));
    return inputArr;
}

string getStr() {
    string strIp;
    getline(cin,strIp);
    return strIp;
}

auto solve() {
    li n;
    cin>>n;
    vector<li> ips = getInts();
    // string s = getStr();

    unm<int,int> um;
    forA(ips) um[i]++;
    // forA(um) cout<<i.x<<" "<<i.y<<endl;
    if(n%2==0) {
        forA(um) if(i.y>n/2) return "NO";
    } else {
        forA(um) {
            if(i.y>n/2) {
                if(i.y==n/2+1) {
                    continue;
                } else {
                    return "NO";
                }
            }
        }
    }
    return "YES";
}

int main() {
    // li t;
    // cin>>t;
    // while(t--) {
        auto ans = solve();
        cout<<ans<<endl;
    // }
    return 0;
}