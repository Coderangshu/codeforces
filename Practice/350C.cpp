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

// PRINT ARRAY, MAP using this templates
template<typename T> void print(T v) {return;}
template<typename T> void print(vector<T> arr) {fa(i,arr) cout<<i<<" ";cout<<endl;}
template<typename T1> void print(vector<vector<T1>> arr) {fa(i,arr) {fa(j,i) cout<<j<<" ";cout<<endl;}}
template<typename T1, typename T2> void print(vector<pair<T1,T2>> arr) {fa(i,arr) cout<<i.x<<" "<<i.y<<"; ";cout<<endl;}
template<typename T> void print(map<T,int> mp) {fa(i,mp) cout<<i.x<<" "<<i.y<<"; ";cout<<endl;}
template<typename T> vector<T> getArr(int n) {vector<T> arr(n);f(i,0,n,1) cin>>arr[i];return arr;}//GET ARRAY AS INPUT OF SIZE N
template<typename T> map<T,int> getMapOfFreq(int n) {map<T,int> mp;f(i,0,n,1) {T e;cin>>e;mp[e]++;}return mp;}//GET ORDERED MAP AS INPUT WITH FREQUENCY OF EACH NUMBER
template<typename T> set<T> getSet(int n) {set<T> st;f(i,0,n,1) {T e;cin>>e;st.insert(e);}return st;}//GET ORDERED SET AS INPUT
int armin(vi &a) {int mn = INT_MAX;fa(i,a) mn = min(mn,i);return mn;}//GET MIN OF ARRAY
int armax(vi &a) {int mx = INT_MIN;fa(i,a) mx = max(mx,i);return mx;}//GET MAX OF ARRAY

auto solve() {
    int n;cin>>n;
    vector<vi> bombs;
    f(i,0,n,1) {
        int a,b;cin>>a>>b;
        int d = a*a+b*b;
        bombs.pb({d,a,b});
    }
    sort(all(bombs));
    // print(bombs);
    vector<string> ans;
    auto pbomb = [&](vi start, vi end) {
        int x = end[1]-start[1], y = end[2]-start[2];
        string s = "1 ";
        if(x<0) s += to_string(-x)+" L";
        else if(x>0) s += to_string(x)+" R";
        if(len(s)>2) ans.pb(s);s = "1 ";
        if(y<0) s += to_string(-y)+" D";
        else if(y>0) s += to_string(y)+" U";
        if(len(s)>2) ans.pb(s);
        return;
    };

    vi origin = {0,0,0};
    fa(bomb,bombs) {
        pbomb(origin,bomb);
        ans.pb(to_string(2));
        pbomb(bomb,origin);
        ans.pb(to_string(3));
    }
    cout<<len(ans)<<endl;
    fa(i,ans) cout<<i<<endl;
}

int32_t main() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);int t = 1;
    // cin>>t;cin.clear();
    while(t--) {
        // cout<<solve()<<endl;
        solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

