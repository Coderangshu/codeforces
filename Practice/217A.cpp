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
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

using ll = long long;
typedef long double ld;
using pii = pair<int, int>;
typedef vector<long long> vi;

// PRINT any datatype using these templates
void print(void) {return;}
template<typename T> void print(T v) {cout<<v<<endl;}
template<typename T> void print(vector<T> arr) {fa(i,arr) cout<<i<<" ";cout<<endl;}
template<typename T1> void print(vector<vector<T1>> arr) {fa(i,arr) {fa(j,i) cout<<j<<" ";cout<<endl;}}
template<typename T1, typename T2> void print(vector<pair<T1,T2>> arr) {fa(i,arr) cout<<i.x<<" "<<i.y<<"; ";cout<<endl;}
template<typename T> void print(map<T,int> mp) {fa(i,mp) cout<<i.x<<" "<<i.y<<"; ";cout<<endl;}
template<typename T> vector<T> getArr(int n) {vector<T> arr(n);f(i,0,n,1) cin>>arr[i];return arr;}//GET ARRAY AS INPUT OF SIZE N
template<typename T> map<T,int> getMapOfFreq(int n) {map<T,int> mp;f(i,0,n,1) {T e;cin>>e;mp[e]++;}return mp;}//GET ORDERED MAP AS INPUT WITH FREQUENCY OF EACH NUMBER
template<typename T> set<T> getSet(int n) {set<T> st;f(i,0,n,1) {T e;cin>>e;st.insert(e);}return st;}//GET ORDERED SET AS INPUT
int armin(vi &a) {int mn = INT_MAX;fa(i,a) mn = min(mn,i);return mn;}//GET MIN OF ARRAY
int armax(vi &a) {int mx = INT_MIN;fa(i,a) mx = max(mx,i);return mx;}//GET MAX OF ARRAY
class UnionFind {
public:
    vi parent,sz;
    int n;
    UnionFind(int n) {
        this->n = n;
        parent.assign(n,0);
        sz.assign(n,1);
        f(i,0,n,1) parent[i] = i;
    }
    void Union(int a, int b) {
        int pra = findParent(a), prb = findParent(b);
        if(pra!=prb) {
            if(sz[pra]>=sz[prb]) {
                parent[prb] = pra;sz[pra]++;
            } else {
                parent[pra] = prb;sz[prb]++;
            }
        }
    }
    int findParent(int a) {
        if(parent[a]==a) return a;
        return parent[a] = findParent(parent[a]);
    }
    void finalize() {
        f(i,0,n,1) findParent(i);
    }
};

auto solve() {
    int n;cin>>n;
    UnionFind uf(n);
    vector<pii> points(n);
    f(i,0,n,1) cin>>points[i].x>>points[i].y;
    f(i,0,n,1) {
        f(j,i+1,n,1) {
            if(points[i].x==points[j].x or points[i].y==points[j].y) {
                uf.Union(i,j);
            }
        }
    }
    uf.finalize();
    unordered_set<int> uns;
    fa(parent,uf.parent) uns.insert(parent);
    return len(uns)-1;
}

int32_t main() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);int t = 1;
    // cin>>t;cin.clear();
    while(t--) {
        cout<<solve()<<endl;
        // solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

