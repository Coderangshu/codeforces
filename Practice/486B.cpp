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
#define f(i, start, end, gap) for(int i=start; i<end; i+=gap)
#define rf(i, start, end, gap) for(int i=start; i>=end; i-=gap)
#define fa(v,arr) for(auto v:arr)
#define rfa(v,arr) for(auto v:reverse(all(arr)))
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
    f(i,0,n,1) cin>>arr[i];
    return arr;
}

// GET UNORDERED MAP AS INPUT WITH FREQUENCY OF EACH NUMBER
template<typename T> unm<T,int> getMapOfFreq(int &n) {
    unm<T,int> um;
    f(i,0,n,1) {
        T e;cin>>e;
        um[e]++;
    }
    return um;
}

// GET UNORDERED SET AS INPUT
template<typename T> uns<T> getSet(int &n) {
    uns<T> us;
    f(i,0,n,1) {
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
        f(i,0,n,1) parent[i] = i;
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
    fa(i,a) mn = min(mn,i);
    return mn;
}

int armax(vi &a) {
    int mx = INT_MIN;
    fa(i,a) mx = max(mx,i);
    return mx;
}

auto solve() {
    int m,n;cin>>m>>n;
    vector<vi> b(m,vi(n));
    f(i,0,m,1) {
        f(j,0,n,1) {
            cin>>b[i][j];
        }
    }
    vector<vi> ans(m,vi(n,1));
    vi row(m), col(n);
    f(i,0,m,1) {
        int k = 0;
        f(j,0,n,1) k += b[i][j];
        if(k==n) row[i] = 1;
    }
    f(i,0,n,1) {
        int k = 0;
        f(j,0,m,1) k += b[j][i];
        if(k==m) col[i] = 1;
    }
    f(i,0,m,1)
        f(j,0,n,1)
            ans[i][j] = (row[i] and col[j]);
    row.assign(m,0);
    col.assign(n,0);
    f(i,0,m,1) {
        int k = 0;
        f(j,0,n,1) k += ans[i][j];
        if(k>0) row[i] = 1;
    }
    f(i,0,n,1) {
        int k = 0;
        f(j,0,m,1) k += ans[j][i];
        if(k>0) col[i] = 1;
    }
    // f(i,0,m,1) {
    //     f(j,0,n,1) cerr<<ans[i][j]<<" ";
    //     cerr<<endl;
    // }
    // fa(i,row) cerr<<i<<" ";
    // cerr<<endl;
    // fa(i,col) cerr<<i<<" ";
    // cerr<<endl;
    f(i,0,m,1) {
        f(j,0,n,1) {
            int e = (row[i] or col[j]);
            if(e!=b[i][j]) {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    f(i,0,m,1) {
        f(j,0,n,1) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin>>t;cin.clear();
    while(t--) {
        // cout<<solve()<<endl;
        solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

