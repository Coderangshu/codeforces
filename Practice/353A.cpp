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

bool isOdd(auto num) {
    return num%2!=0;
}

auto solve() {
    li n, upper, lower, oddCountUp = 0, oddCountDown = 0;
    li bothOdd = 0;
    cin>>n;
    while(n--) {
        cin>>upper>>lower;
        if(isOdd(upper) and isOdd(lower)) bothOdd++;
        else if(isOdd(upper)) oddCountUp++;
        else if(isOdd(lower)) oddCountDown++;
    }
    // cout<<oddCountUp<<" "<<oddCountDown<<" "<<bothOdd<<endl; 

    if(bothOdd%2==0) {
        if(oddCountDown+oddCountUp==0) return 0;
        else if(oddCountUp%2==0 and oddCountDown%2==0) return 0;
        else if((oddCountUp%2==0 and oddCountDown%2==1) or (oddCountUp%2==1 and oddCountDown%2==0)) return -1;
        else return 1;
    } else {
        if(oddCountDown+oddCountUp==0) return -1;
        else if(oddCountUp%2==0 and oddCountDown%2==0) return 1;
        else if((oddCountUp%2==0 and oddCountDown%2==1) or (oddCountUp%2==1 and oddCountDown%2==0)) return -1;
        else return 0;
    }
}

int main() {
    // li t;
    // cin>>t;
    // while(t--)
        cout<<solve()<<endl;
    return 0;
}