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

void getNoOfDivisors(li num, vector<li> &v) {
    if(v[num]!=0) return;
    li ans = 0;
    for(li i=2;i<num;i++) {
        if(num%i==0) ans++;
    }
    v[num] = ans+2;
}

auto solve() {
    li a,b,c,ans = 0, mod = 2e30;
    cin>>a>>b>>c;
    vector<li> v(a*b*c+1);
    for(li i=1;i<=a;i++) {
        for(li j=1;j<=b;j++) {
            for(li k=1;k<=c;k++) {
                li num = i*j*k;
                getNoOfDivisors(num,v);
                ans += v[num];
            }
        }
    }
    return (ans-1)%mod;
}

int main() {
    // li t;
    // cin>>t;
    // while(t--)
        cout<<solve()<<endl;
    return 0;
}