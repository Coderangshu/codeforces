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
    string input,output;
    cin>>input>>output;
    // cout<<input<<" "<<output;
    li i=0,j=0, is = input.size(), os = output.size();
    while(i<is and j<os) {
        if(input[i]==output[j] or input[i]=='?')
            input[i++] = output[j++];
        else if(input[i]=='?')
            input[i++] = 'a';
        else i++;
    }
    while(i<is) {
        if(input[i]=='?') input[i] = 'b';
        i++;
    }
    if(j>=os)
        cout<<"YES\n"<<input<<endl;
    else cout<<"NO"<<endl;
    return;
}

int main() {
    li t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}