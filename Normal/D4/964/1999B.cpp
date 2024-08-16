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

li score(li a, li b) {
    if(a<b) return -1;
    else if(a==b) return 0;
    else return 1;
}

auto solve() {
    li a1,a2,b1,b2;
    cin>>a1;
    cin>>a2;
    cin>>b1;
    cin>>b2;
    li ans = 0;
    if(score(a1,b1)+score(a2,b2)>0) ans++;
    if(score(a1,b2)+score(a2,b1)>0) ans++;
    if(score(a2,b1)+score(a1,b2)>0) ans++;
    if(score(a2,b2)+score(a1,b1)>0) ans++;
    return ans;
}

int main() {
    li t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
    return 0;
}