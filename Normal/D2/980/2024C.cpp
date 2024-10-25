#include<bits/stdc++.h>
using namespace std;

#define int ll
#define x first
#define y second
#define pb push_back
#define bs binary_search
#define ub upper_bound
#define lb lower_bound
#define len(a) (long long)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define f(i, start, end, gap) for(long long  i=start; i<end; i+=gap)
#define rf(i, start, end, gap) for(long long i=start; i>=end; i-=gap)
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

// PRINT ARRAY, MAP using this templates
template<typename T> void print(T v) {return;}
template<typename T> void print(vector<T> arr) {fa(i,arr) cout<<i<<" ";cout<<endl;}
template<typename T1, typename T2> void print(vector<pair<T1,T2>> arr) {fa(i,arr) cout<<i.x<<" "<<i.y<<"; ";cout<<endl;}
template<typename T> void print(unm<T,int> um) {fa(i,um) cout<<i.x<<" "<<i.y<<"; ";cout<<endl;}
template<typename T> void print(map<T,int> mp) {fa(i,mp) cout<<i.x<<" "<<i.y<<"; ";cout<<endl;}

// GET ARRAY AS INPUT OF SIZE N
template<typename T> vector<T> getArr(int &n) {vector<T> arr(n);f(i,0,n,1) cin>>arr[i];return arr;}

// GET UNORDERED MAP AS INPUT WITH FREQUENCY OF EACH NUMBER
template<typename T> unm<T,int> getUmapOfFreq(int &n) {unm<T,int> um;f(i,0,n,1) {T e;cin>>e;um[e]++;}return um;}

// GET ORDERED MAP AS INPUT WITH FREQUENCY OF EACH NUMBER
template<typename T> map<T,int> getMapOfFreq(int &n) {map<T,int> mp;f(i,0,n,1) {T e;cin>>e;mp[e]++;}return mp;}

// GET UNORDERED SET AS INPUT
template<typename T> uns<T> getSet(int &n) {uns<T> us;f(i,0,n,1) {T e;cin>>e;us.insert(e);}return us;}

// GET MIN OF ARRAY
int armin(vi &a) {int mn = INT_MAX;fa(i,a) mn = min(mn,i);return mn;}

// GET MAX OF ARRAY
int armax(vi &a) {int mx = INT_MIN;fa(i,a) mx = max(mx,i);return mx;}

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


auto solve() {
    int n;cin>>n;
    vector<pii> an(n);
    vi ann(2*n);
    f(i,0,n,1) {
        int a,b;cin>>a>>b;
        an[i] = {a,b};
        ann[2*i] = a;
        ann[2*i+1] = b;
    }

    sort(all(ann));
    unm<int ,int> mp;
    int ind = 0;
    f(i,0,2*n,1) {
        if(mp.count(ann[i])==0) mp[ann[i]] = ind++;
    }

    vector<pii> compressed(n);
    f(i,0,n,1) {
        compressed[i].x = mp[an[i].x];
        compressed[i].y = mp[an[i].y];
    }

    vector<vi> ans(n,vi(3,0));
    f(i,0,n,1) {
        int sum = compressed[i].x + compressed[i].y;
        ans[i][0] = sum;
        ans[i][1] = an[i].x;
        ans[i][2] = an[i].y;
    }

    sort(all(ans),[](const vi &a, const vi &b){
        return a[0]<b[0];
    });

    f(i,0,n,1) {
        cout<<ans[i][1]<<" "<<ans[i][2]<<" ";
    }
    cout<<endl;
    return;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);int t = 1;
    cin>>t;cin.clear();
    while(t--) {
        // cout<<solve()<<endl;
        solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

