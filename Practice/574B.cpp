#include<bits/stdc++.h>
using namespace std;

#define int ll
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define len(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forl(i,n) for(int i = 0; i < int(n); i++)
#define forr(i,n) for(int i = n-1; i > -1; i--)
#define fore(i, l, r) for(int i = int(l); i <= int(r); i++)
#define fora(v,arr) for(auto v:arr)
#define unm unordered_map
#define uns unordered_set
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN

using ll = long long;
typedef long double ld;
using pii = pair<int, int>;
typedef vector<long long> vi;

// GET ARRAY AS INPUT OF SIZE N
template<typename T> vector<T> getArr(int &n) {
    vector<T> arr(n);
    forl(i,n) cin>>arr[i];
    return arr;
}

// GET UNORDERED MAP AS INPUT WITH FREQUENCY OF EACH NUMBER
template<typename T> unm<T,int> getMapOfFreq(int &n) {
    unm<T,int> um;
    forl(i,n) {
        T e;cin>>e;
        um[e]++;
    }
    return um;
}

// GET UNORDERED SET AS INPUT
template<typename T> uns<T> getSet(int &n) {
    uns<T> us;
    forl(i,n) {
        T e;cin>>e;
        us.insert(e);
    }
    return us;
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


int armin(vi &a) {
    int mn = INT_MAX;
    fora(i,a) mn = min(mn,i);
    return mn;
}

int armax(vi &a) {
    int mx = INT_MIN;
    fora(i,a) mx = max(mx,i);
    return mx;
}

auto solve() {
    int n,m;cin>>n>>m;
    uns<int> adj[n];
    while(m--) {
        int u,v;cin>>u>>v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int ans = INT_MAX;
    forl(i,n) {
        forl(j,n) {
            if(adj[j].count(i)) {
                forl(k,n) {
                    if(adj[k].count(i) and adj[k].count(j)) {
                        int sor = adj[i].size()+adj[j].size()+adj[k].size()-6;
                        ans = min(ans,sor);
                    } else continue;
                }
            } else continue;
        }
    }
    return (ans==INT_MAX)?-1:ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin>>t;cin.clear()
    while(t--) {
        cout<<solve()<<endl;
        // solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

