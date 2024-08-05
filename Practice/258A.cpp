#include<bits/stdc++.h>
using namespace std;

vector<int> getInts() {
    string strIp;
    vector<int> inputArr;
    while (getline(cin, strIp, ' ')) {
        inputArr.push_back(atoi(strIp.c_str()));
    }
    return inputArr;
}

string getStr() {
    string strIp;
    getline(cin,strIp);
    return strIp;
}

void solve() {
    // int n;
    // cin>>n;
    // vector<int> ips = getInts();
    // string s = getStr();

    string s;
    cin>>s;
    int n = s.length();

    int i = 0;
    for(;i<n;i++) if(s[i]=='0') break;
    if(i==n) {
        cout<<s.substr(1)<<endl;
    } else 
        cout<<s.substr(0,i)+s.substr(i+1)<<endl;

    return;
}

int main() {
    // int t;
    // cin>>t;
    // while(t--)
        solve();
    return 0;
}