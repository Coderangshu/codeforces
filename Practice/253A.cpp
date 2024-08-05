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

auto solve() {
    auto arr = getInts(2);
    string ans = "";
    while(arr[0]!=0 and arr[1]!=0) {
        ans += "BG";
        arr[0]--;
        arr[1]--;
    }
    while(arr[0]!=0) {
        ans += "B";
        arr[0]--;
    }
    while(arr[1]!=0) {
        ans += "G";
        arr[1]--;
    }
    return ans;
}

int main() {
    // cin>>t;
    // while(t--)
        cout<<solve()<<endl;
    return 0;
}