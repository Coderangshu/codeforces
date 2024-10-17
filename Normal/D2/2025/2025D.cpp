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
    int n,m;cin>>n>>m;
    vi r = getArr<int>(n);
    int totPoint = 0;
    // cur and prev will store the intelligence tests passed
    // size of cur and prev is totPoint upto now
    // example - if totPoint = 7 then cur[3] contains the # of tests passed
    // when 3 points are given to intelligence and (7-3=) 4 points are given to
    // strength
    vi cur, prev, ichk, schk;
    f(i,0,n,1) {
        if(r[i]>0) ichk.pb(r[i]);
        else if(r[i]<0) schk.pb(-r[i]);
        else {
            totPoint++;
            cur.assign(totPoint,0ll);
            if(len(prev)==0) {
                prev = cur;
                continue;
            }
            sort(all(ichk));
            sort(all(schk));
            cout<<"ICHK ";print(ichk);
            cout<<"SCHK ";print(schk);
            f(j,0,totPoint+1,1) {
                cout<<"J "<<j<<endl;
                // giving this point to both intelligence and strength
                // then we will calculate the max of both

                // if this point is given intelligence, thus now intelligence point
                // will be j thus we take the tests passed when intelligence had j-1
                // points in the prev state
                if(j>0) {
                    int prevIPnt = j-1, prevSPnt = (totPoint-1)-(j-1);
                    // # of tests passed from last point collected upto this point before adding this point
                    int newTestsPassed = (ub(all(ichk),prevIPnt)-ichk.begin()) + (ub(all(schk),prevSPnt)-schk.begin());
                    cout<<"I "<<newTestsPassed<<endl;
                    cout<<"PREV[j-1] ";print(prev);
                    cur[j] = max(cur[j],prev[j-1]+newTestsPassed);
                }
                // if this point is given to strength then earlier and now intelligence point
                // will be same so we use the jth value of previous array
                if(j<totPoint) {
                    int prevIPnt = j, prevSPnt = (totPoint-1)-j;
                    int newTestsPassed = (ub(all(ichk),prevIPnt)-ichk.begin()) + (ub(all(schk),prevSPnt)-schk.begin());
                    cout<<"S "<<newTestsPassed<<endl;
                    cur[j] = max(cur[j],prev[j]+newTestsPassed);
                }
                cout<<"PREV ";print(prev);
                cout<<"CUR ";print(cur);
            }
            ichk.clear(),schk.clear();
            prev = cur;
            print(prev);
        }
        
    }sort(all(ichk)), sort(all(schk));
    // at end all the m points have been added to the prev
    // now if any pending tests have occured after the last point that needs to be added
    int ans = 0;
    f(i,0,m+1,1) {
        int ipnts = i, spnts = m-i;
        int newTestsPassed = (ub(all(ichk),ipnts)-ichk.begin()) + (ub(all(schk),spnts)-schk.begin());
        ans = max(ans,prev[i]+newTestsPassed);
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);int t = 1;
    // cin>>t;cin.clear();
    while(t--) {
        cout<<solve()<<endl;
        // solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

