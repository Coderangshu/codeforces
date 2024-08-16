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
    li n, n2, ans = 0;
    cin>>n;
    // cout<<n<<endl;
    n2 = n*n;
    // cout<<n2<<endl;
    for(li i=1;i<=n;i++) {
        li i2 = i*i;
        for(li j=i+1;j<=n;j++) {
            li j2 = j*j;
            li k2 = i2+j2;
            // cout<<"lsdkfjdslkjf "<<i2<<" "<<j2<<" "<<k2<<endl;
            if(k2<=n2) {
                ld sk2 = sqrt(k2);
                // cout<<sk2<<" "<<int(sk2)<<endl;
                if(sk2==int(sk2)) ans++;
                // cout<<i2<<" "<<j2<<" "<<ans<<endl;
            } else break;
        }
    }
    return ans;
}

int main() {
    // int t;
    // cin>>t;
    // while(t--)
        cout<<solve()<<endl;
    return 0;
}