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

int n = 10e6+1;
vector<bool> sieve;

void calculateSieveOfEratosthenes() {
    sieve[0] = sieve[1] = 0;
    for(int i=2;i*i<n;i++) {
        if(sieve[i]) {
            for(int j=i*i;j<n;j+=i) sieve[j] = false;
        }
    }
    return;
}

auto solve() {
    int n; cin>>n;
    while(n--) {
        long double i;cin>>i;
        int srt = sqrtl(i);
        // cout<<i<<" "<<srt<<" "<<sieve[srt]<<endl;
        if(pow(srt,2)==i and sieve[srt]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    // int t; cin>>t;
    // while(t--)
        // cout<<solve()<<endl;
        sieve.assign(n,true);
        calculateSieveOfEratosthenes();
        solve();
}