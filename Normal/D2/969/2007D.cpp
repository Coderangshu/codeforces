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
    vi gs() {return size;}
};

auto solve() {
    int n;cin>>n;
    // cerr<<n<<endl;
    vi degree(n);
    forl(i,n-1) {
        int u,v;cin>>u>>v;
        degree[u-1]++;
        degree[v-1]++;
    }
    string s;cin>>s;
    int one = 0, zero = 0, question = 0, insideQuestion = 0;
    fore(1,n-1) {
        if(degree[i]==1) {
            if(s[i]=='1') one++;
            else if(s[i]=='0') zero++;
            else question++;
        } else if(s[i]=='?') insideQuestion++;
    }
    if(s[0]=='1') {
        return zero+(question+1)/2;
    } else if(s[0]=='0') {
        return one+(question+1)/2;
    } else {
        int ans = max(one,zero);
        if(one==zero) question += insideQuestion%2;
        ans += question/2;
        return ans;
    }
    return 0ll;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin>>t;
    cin.clear();
    // cerr<<t<<endl;
    while(t--) {
        cout<<solve()<<endl;
        // solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

