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

void push2PQ(int n, string num, priority_queue<int,vector<int>,greater<int>> &pq) {
    int i = 0;
    while(n--) {
        char s = num[i++];
        pq.push(int(s));
    }
}

auto solve() {
    li n, tn;
    cin>>n;
    string num;
    cin>>num;
    // cout<<num<<endl;
    tn = n;
    priority_queue<int,vector<int>,greater<int>> minpq1, minpq2;
    
    push2PQ(n,num,minpq1);
    num = num.substr(n);
    push2PQ(n,num,minpq2);

    int t1 = minpq1.top(), t2 = minpq2.top();
    minpq1.pop();
    minpq2.pop();

    bool flag = true;
    // cout<<t1<<" "<<t2<<endl;
    if(t1==t2) return "NO";
    else if(t1<t2) flag = false;

    while(!minpq1.empty()) {
        t1 = minpq1.top(), t2 = minpq2.top();
        minpq1.pop();
        minpq2.pop();
        // cout<<t1<<" "<<t2<<endl;
        if(t1==t2) return "NO";
        else if((flag and t1<t2) or (!flag and t1>t2)) return "NO";
    }
    return "YES";
}

int main() {
    // li t;
    // cin>>t;
    // while(t--)
        cout<<solve()<<endl;
    return 0;
}