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

auto solve() {
    int n;cin>>n;
    vector<pii> a;
    vi f, s;
    f(i,0,n,1) {
        int e;cin>>e;
        a.pb({e,i+1});
    }
    make_heap(all(a));
    bool rev = false;
    while(len(a)!=0) {
        pop_heap(all(a));
        auto [largest,li] = a.back();
        int secondLargest = -1, sli = -1;
        a.pop_back();
        if(len(a)>0) {
            pop_heap(all(a));
            auto pr = a.back();
            secondLargest = pr.x;
            sli = pr.y;
            a.pop_back();
        }
        if (rev) {
            s.pb(li);
            if(secondLargest!=-1) f.pb(sli);
        } else {
            f.pb(li);
            if(secondLargest!=-1) s.pb(sli);
        }
        rev = !rev;
    }
    cout<<len(s)<<endl;
    print(s);
    cout<<len(f)<<endl;
    print(f);
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

