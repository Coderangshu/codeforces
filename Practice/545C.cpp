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

// unm<int,int> um;
vi dp;
vector<pii> xh;

int recursion(int i, int availablePosition) {
    int n = len(xh);
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    // cerr<<i<<endl;
    // fa(i,xh) cerr<<i.x<<"; ";
    // cerr<<endl;
    // fa(i,xh) cerr<<i.y<<"; ";
    // cerr<<endl;
    int ans = recursion(i+1,xh[i].x);
    // fall left
    if(i==0 or xh[i].x-xh[i].y>availablePosition) ans = max(ans, recursion(i+1, xh[i].x)+1);
    // fall right
    if(availablePosition<xh[i].x) ans = max(ans, 1 + recursion(i+1,xh[i].x+xh[i].y));
    return dp[i] = ans;
}

auto solve() {
    int n;cin>>n;
    dp.assign(n,-1);
    xh.assign(n,{0,0});
    f(i,0,n,1) {
        int xi,h;cin>>xi>>h;
        xh[i] = {xi,h};
    }
    // vi ans(n);
    // rf(i,n-1,0,1) {
    //     rf(availablePosition,xh[n-1].x+xh[n-1].y+10,0p) {
    //         int ans = recursion(i+1,xh[i].x);
    //         // fall left
    //         if(i==0 or xh[i].x-xh[i].y>availablePosition) ans++;
    //         // fall right
    //         if(i==n-1 or xh[i].x+xh[i].y<xh[i+1].x) ans = max(ans, 1 + recursion(i+1,xh[i].x+xh[i].y));
    //         return um[i] = ans;
    //     }
    // }
    // return recursion(0,INT_MIN);
    int ans = 1;
    f(i,1,n-1,1) {
        if(xh[i].x-xh[i-1].x>xh[i].y) ans++;
    }
    ans++;
    int tans = 1;
    rf(i,n-2,1,1) {
        if(xh[i+1].x-xh[i].x>xh[i].y) tans++;
    }
    tans++;
    return max(tans,ans);
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin>>t;cin.clear();
    while(t--) {
        cout<<solve()<<endl;
        // solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

