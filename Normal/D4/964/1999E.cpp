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

vector<int> prefixSum;

li getCount(li n) {
    li ans = 0;
    while(n) {
        n /= 3;
        ans++;
    }
    return ans;
}

auto solve() {
    li l,r;
    cin>>l>>r;
    return prefixSum[r]-prefixSum[l-1]+prefixSum[l]-prefixSum[l-1];
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(nullptr);

    prefixSum.assign(2e5+10,0);
    for(int i=1;i<=2e5+1;i++) {
        prefixSum[i] = getCount(i)+prefixSum[i-1];
    }

    li t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
    return 0;
}