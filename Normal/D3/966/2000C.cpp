// #include<bits/stdc++.h>
// using namespace std;

// #define int ll
// #define x first
// #define y second
// #define mp make_pair
// #define pb push_back
// #define sqr(a) ((a) * (a))
// #define sz(a) int(a.size())
// #define all(a) a.begin(), a.end()
// #define forn(n) for(int i = 0; i < int(n); i++)
// #define forR(n) for(int i = n-1; i > -1; i--)
// #define fore(l, r) for(int i = int(l); i < int(r); i++)
// #define forA(arr) for(auto i:arr)
// #define unm unordered_map
// #define uns unordered_set

// using ll = long long;
// typedef long double ld;
// using pii = pair<int, int>;
// typedef vector<long long> vi;

// vector<int> getInts(int n) {
//     vi arr(n);
//     forn(n) cin>>arr[i];
//     return arr;
// }

// string getStr() {
//     string strIp;
//     getline(cin,strIp);
//     return strIp;
// }

// auto solve() {
//     int n; cin>>n;
//     vi a(n);
//     forn(n) cin>>a[i];
//     int m;cin>>m;
//     // cout<<m<<endl;
//     // cout<<"dlskfjsd"<<endl;
//     while(m--) {
//         // cout<<m<<endl;
//         string s; cin>>s;
//         int ns = s.length();
//         if(ns!=n) {
//             cout<<"NO"<<endl;
//             continue;
//         }
//         unm<int,char> um;
//         unm<char,int> um1;
//         bool ans = true;
//         forn(n) {
//             if(um.count(a[i])>0) {
//                 if(s[i]!=um[a[i]]) {
//                     ans = false;
//                     break;
//                 }
//             } else {
//                 um[a[i]] = s[i];
//             }
//         }
//         if(!ans) {
//             cout<<"NO"<<endl;
//             continue;
//         } else {
//             forn(n) {
//                 if(um.count(s[i])>0) {
//                     if(a[i]!=um[s[i]]) {
//                         ans = false;
//                         break;
//                     }
//                 } else {
//                     um[s[i]] = a[i];
//                 }
//             }
//         }
//         if(!ans) cout<<"NO"<<endl;
//         else cout<<"YES"<<endl;
//     }
//     return;
// }

// int32_t main() {
//     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//     int t; cin>>t;
//     // cout<<t<<endl;
//     while(t--)
//         solve();
// }


#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

void check_string_matches(int t, vector<vector<int>> &test_cases, vector<vector<string>> &strings) {
    for (int case_idx = 0; case_idx < t; ++case_idx) {
        int n = test_cases[case_idx].size();
        vector<int> &template_array = test_cases[case_idx];
        vector<string> &case_strings = strings[case_idx];

        for (const string &s : case_strings) {
            if (s.length() != n) {
                cout << "NO" << endl;
                continue;
            }
            
            unordered_map<int, char> template_to_char;
            unordered_map<char, int> char_to_template;
            bool match = true;

            for (int i = 0; i < n; ++i) {
                int num = template_array[i];
                char c = s[i];

                if (template_to_char.count(num) > 0) {
                    if (template_to_char[num] != c) {
                        match = false;
                        break;
                    }
                }

                if (char_to_template.count(c) > 0) {
                    if (char_to_template[c] != num) {
                        match = false;
                        break;
                    }
                }

                template_to_char[num] = c;
                char_to_template[c] = num;
            }

            if (match) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    vector<vector<int>> test_cases(t);
    vector<vector<string>> strings(t);

    for (int case_idx = 0; case_idx < t; ++case_idx) {
        int n;
        cin >> n;
        test_cases[case_idx].resize(n);

        for (int i = 0; i < n; ++i) {
            cin >> test_cases[case_idx][i];
        }

        int m;
        cin >> m;
        strings[case_idx].resize(m);

        for (int i = 0; i < m; ++i) {
            cin >> strings[case_idx][i];
        }
    }

    check_string_matches(t, test_cases, strings);

    return 0;
}
