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
    li n,s,m;
    cin>>n>>s>>m;
    bool ans = false;
    li start = 0,l,r;
    while(n--) {
        cin>>l>>r;
        if(l-start>=s) ans = true;
        start = r;
    }
    if(m-start>=s) ans = true;
    return (ans==true)?"YES":"NO";
}

int main() {
    li t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
    return 0;
}