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
    li n;
    cin>>n;
    vector<li> ips = getInts(n);
    li balance = 0;
    forA(ips) {
        balance += i;
    }
    return (balance==0 or balance%n==0)?n:n-1;
}

int main() {
    // li t;
    // cin>>t;
    // while(t--)
        cout<<solve()<<endl;
    return 0;
}