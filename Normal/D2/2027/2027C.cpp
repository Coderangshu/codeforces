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

using ll = long long;
typedef long double ld;
using pii = pair<int, int>;
typedef vector<long long> vi;

// PRINT ARRAY, MAP using this templates
template<typename T> void print(T v) {return;}
template<typename T> void print(vector<T> arr) {fa(i,arr) cout<<i<<" ";cout<<endl;}
template<typename T1, typename T2> void print(vector<pair<T1,T2>> arr) {fa(i,arr) cout<<i.x<<" "<<i.y<<"; ";cout<<endl;}
template<typename T> void print(map<T,int> mp) {fa(i,mp) cout<<i.x<<" "<<i.y<<"; ";cout<<endl;}

// GET ARRAY AS INPUT OF SIZE N
template<typename T> vector<T> getArr(int &n) {vector<T> arr(n);f(i,0,n,1) cin>>arr[i];return arr;}

// GET ORDERED MAP AS INPUT WITH FREQUENCY OF EACH NUMBER
template<typename T> map<T,int> getMapOfFreq(int &n) {map<T,int> mp;f(i,0,n,1) {T e;cin>>e;mp[e]++;}return mp;}

// GET ORDERED SET AS INPUT
template<typename T> set<T> getSet(int &n) {set<T> st;f(i,0,n,1) {T e;cin>>e;st.insert(e);}return st;}

// GET MIN OF ARRAY
int armin(vi &a) {int mn = INT_MAX;fa(i,a) mn = min(mn,i);return mn;}

// GET MAX OF ARRAY
int armax(vi &a) {int mx = INT_MIN;fa(i,a) mx = max(mx,i);return mx;}

unordered_map<int, vi> unm;
map<int, int> dp;

int recursion(int ind) {
    if (dp.count(ind)) return dp[ind];
    int ans = ind;
    if (unm.count(ind)) {
        fa(i,unm[ind]) {
            int newi = ind + i - 1;
            ans = max(ans, recursion(newi));
        }
    }
    return dp[ind] = ans;
}

auto solve() {
    unm.clear();
    dp.clear();
    int n;cin>>n;
    vi arr(n+1);
    f(i,1,n+1,1) cin >> arr[i];
    f(i,2,n+1,1) {
        int ni = arr[i] + i - 1;
        unm[ni].push_back(i);
    }
    int ans = recursion(n);
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);int t = 1;
    cin>>t;cin.clear();
    while(t--) {
        cout<<solve()<<endl;
        // solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

