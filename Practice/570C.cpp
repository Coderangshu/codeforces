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
    int n,m; string s;cin>>n>>m>>s;
    int start = -1, end, ans = 0;
    f(i,0,n,1) {
        if(start==-1 and s[i]=='.') start = end = i;
        else {
            if(s[i]=='.') end = i;
            else {
                if(start==-1) continue;
                ans += (end-start);
                start = -1;
            }
        }
    }
    if(start!=-1) ans += (end-start);
    s = 'a'+s+'a';
    // cerr<<ans<<endl;
    while(m--) {
        int i; char c;cin>>i>>c;
        if(s[i]!='.' and c=='.') {
            if(s[i+1]==s[i-1] and s[i-1]=='.') ans += 2;
            else if(s[i-1]=='.' or s[i+1]=='.') ans++;
        } else if(s[i]=='.' and c!='.') {
            if(s[i+1]==s[i-1] and s[i+1]=='.') ans -= 2;
            else if(s[i-1]=='.' or s[i+1]=='.') ans--;
        }
        s[i] = c;
        cout<<ans<<endl;
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

