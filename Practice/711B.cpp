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
    vi square[n];
    int c,r, rsm = 0, csm = 0, d1sm = 0, d2sm = 0, actualSm = 0, ans = -1;
    forl(i,n) {
        forl(j,n) {
            int e;cin>>e;
            if(!e) {
                c = j;
                r = i;
            }
            square[i].pb(e);
        }
    }
    // cerr<<r<<" "<<c<<endl;
    forl(i,n) if(i!=r) {
        fora(j,square[i]) actualSm += j;
        break;
    }
    if(n==1) return 69ll;
    // row sum
    fora(i,square[r]) rsm += i;
    // col sum
    forl(i,n) csm += square[i][c];
    if(r==c) {
        forl(i,n) d1sm += square[i][i];
    }
    if(r+c==n-1) {
        forl(i,n) d2sm += square[i][n-1-i];
    }
    ans = actualSm - rsm;
    // cerr<<actualSm<<" "<<rsm<<" "<<csm<<" "<<d1sm<<" "<<d2sm<<endl;
    if(ans<=0) return -1ll;
    if(actualSm-csm!=ans) return -1ll;
    if(d1sm!=0 and actualSm-d1sm!=ans) return -1ll;
    if(d2sm!=0 and actualSm-d2sm!=ans) return -1ll;
    // check new magic square
    square[r][c] = ans;
    forl(i,n) {
        int sm = 0;
        fora(j,square[i]) sm += j;
        if(sm!=actualSm) return -1ll;
    }
    forl(i,n) {
        int sm = 0;
        forl(j,n) sm += square[j][i];
        if(sm!=actualSm) return -1ll;
    }
    int dsm = 0, dssm = 0;
    forl(i,n) {
        dsm += square[i][i];
        dssm += square[i][n-1-i];
    }
    if(dsm!=actualSm or dssm!=actualSm) return -1ll;
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin>>t;cin.clear()
    while(t--) {
        cout<<solve()<<endl;
        // solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

