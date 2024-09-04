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
#define forl(i,n) for(int i = 0; i < int(n); i++)
#define forr(i,n) for(int i = n-1; i > -1; i--)
#define fore(l, r) for(int i = int(l); i <= int(r); i++)
#define fora(v,arr) for(auto v:arr)
#define unm unordered_map
#define uns unordered_set
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN

using ll = long long;
typedef long double ld;
using pii = pair<int, int>;
typedef vector<long long> vi;

// GET INTEGER ARRAY AS INPUT OF SIZE N
vi getInts(int n) {
    vi arr(n);
    forl(i,n) cin>>arr[i];
    return arr;
}

// GET A STRING WITH SPACE AS A SINGLE STRING IN INPUT
string getStr() {
    string strIp;
    getline(cin,strIp);
    return strIp;
}

// UNION FIND CLASS
class UnionFind {
    vi parent, size;
    public:
    UnionFind(int n) {
        this->parent.resize(n);
        this->size.assign(n,1);
        forl(i,n) parent[i] = i;
    }

    void Union(int a, int b) {
        int pa = this->findParent(a), pb = this->findParent(b);
        if(this->size[pa]>=this->size[pb]) {
            this->parent[pb] = pa;
            this->size[pa]++;
        } else {
            this->parent[pa] = pb;
            this->size[pb]++;
        }
    }

    int findParent(int a) {
        if(this->parent[a]==a) return a;
        return parent[a] = this->findParent(parent[a]);
    }

    vi getParentArr() {return this->parent;}
};

auto solve() {
    int n;cin>>n;
    vector<int> p(n);
    vector<int> F(n, 0);
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    
    string s;
    cin >> s;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> cycle;
            int black_count = 0;
            int x = i;
            
            while (!visited[x]) {
                visited[x] = true;
                cycle.push_back(x);
                if (s[x] == '0') {
                    black_count++;
                }
                x = p[x];
            }
            
            for (int j : cycle) {
                F[j] = black_count;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << F[i] << " ";
    }
    cout << endl;
    // return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--) {
        // cout<<solve()<<endl;
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}