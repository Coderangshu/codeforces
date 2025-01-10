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

void dfs (vi *adj, int u, unordered_set<int> &vis, stack<int> &stk) {
    fa(v,adj[u]) {
        if(vis.count(v)==0) {
            vis.insert(v);
            dfs(adj,v,vis,stk);
        }
    }
    stk.push(u);
    return;
}

void dfs2 (vi *adj, int u, unordered_set<int> &vis, vi &nodes) {
    fa(v,adj[u]) {
        if(vis.count(v)==0) {
            vis.insert(v);
            nodes.pb(v);
            dfs2(adj, v, vis, nodes);
        }
    }
    return;
}

vector<vi> kosaraju(vi *adj, int n) {
    stack<int> stk;
    unordered_set<int> vis;
    f(i,0,n,1) if(vis.count(i)==0) {
        vis.insert(i);
        dfs(adj,i,vis,stk);
    }

    vi adjT[n];
    f(u,0,n,1) fa(v,adj[u]) adjT[v].pb(u);

    vis.clear();
    vector<vi> components;
    while(!stk.empty()) {
        int u = stk.top(); stk.pop();
        if(vis.count(u)==0) {
            vi nodes = {u};
            vis.insert(u);
            dfs2(adjT,u,vis,nodes);
            components.pb(nodes);
        }
    }
    return components;
}

auto solve() {
    int n;cin>>n;
    vi prices = getArr<int>(n);
    int m;cin>>m;
    vi adj[n];
    f(i,0,m,1) {
        int u,v;cin>>u>>v;u--,v--;
        adj[u].pb(v);
    }
    vector<vi> components = kosaraju(adj,n);
    int ans = 0, ways = 1, mod = 1e9+7;

    fa(scc,components) {
        int mn = INT_MAX, count = 0;
        fa(node,scc) {
            if(prices[node]<mn) {
                mn = prices[node];
                count = 1;
            } else if(prices[node]==mn) count++;
        }
        ans += mn;
        ways = (ways*count)%mod;
    }
    cout<<ans<<" "<<ways<<endl;
    return;
}

int32_t main() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);int t = 1;
    // cin>>t;cin.clear();
    while(t--) {
        // cout<<solve()<<endl;
        solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

