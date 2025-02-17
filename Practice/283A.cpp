#include<bits/stdc++.h>
using namespace std;

#define int ll
#define ft first
#define sd second
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
    vi nums(n+1,0), diff(n+1,0);
    int i = 0, sum = 0;
    while(n--) {
        int choice;cin>>choice;
        if(choice==1) {
            int ai,xi;cin>>ai>>xi;
            diff[ai-1] += xi;
            sum += ai*xi;
        } else if(choice==2) {
            int ki;cin>>ki;
            nums[++i] = ki;
            sum += ki;
        } else {
            sum -= nums[i]+diff[i];
            diff[i-1] += diff[i];
            diff[i] = 0;
            i--;
        }
        cout<<fixed<<setprecision(6)<<(ld)sum/(double)(i+1)<<endl;
    }
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

