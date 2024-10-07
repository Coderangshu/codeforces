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
#define forl(i,n) for(int i = 0; i < int(n); i++)
#define forr(i,n) for(int i = n-1; i > -1; i--)
#define fore(i, l, r) for(int i = int(l); i <= int(r); i++)
#define fora(v,arr) for(auto v:arr)
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
    forl(i,n) cin>>arr[i];
    return arr;
}

// GET UNORDERED MAP AS INPUT WITH FREQUENCY OF EACH NUMBER
template<typename T> unm<T,int> getMapOfFreq(int &n) {
    unm<T,int> um;
    forl(i,n) {
        T e;cin>>e;
        um[e]++;
    }
    return um;
}

// GET UNORDERED SET AS INPUT
template<typename T> uns<T> getSet(int &n) {
    uns<T> us;
    forl(i,n) {
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
        forl(i,n) parent[i] = i;
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
    fora(i,a) mn = min(mn,i);
    return mn;
}

int armax(vi &a) {
    int mx = INT_MIN;
    fora(i,a) mx = max(mx,i);
    return mx;
}

bool isPossible(int ds, int k, vi &a) {
    fora(i,a) k -= max(0ll,ds-i);
    return (k<0)?false:true;
}

auto solve1() {
    int n,k;cin>>n>>k;
    vi a = getArr<int>(n);
    int mx = armax(a);
    int sum = accumulate(all(a),0ll);
    // largest possible size of each deck can be n
    // we consider ans as n to begin with
    int ans = n, totCards = sum+k;
    while(ans>=1) {
        // totCards should be divisible by ans as each stack will contain ans no of cards
        // thus making it divisible
        totCards = (sum+k)-(sum+k)%ans;
        // if now totCards < cards already with him then this ans is not possible
        // decrement ans and check for that ans
        if(totCards>=sum) {
            int noOfStacks = totCards/ans;
            if(mx<=noOfStacks) return ans;
            else ans--;
        } else ans--;
    }
    return ans+1;
}

int n,k,sum=0,mx=INT_MIN;
bool psbl(int m) {
    int totcards = ((sum+k)/m)*m;
    if(totcards>=sum) {
        if(totcards/m<mx) return false;
        return true;
    }
    return false;
}

auto solve() {
    sum = 0, mx = INT_MIN;
    cin>>n>>k;
    forl(i,n) {
        int e;cin>>e;
        sum += e;
        mx = max(mx,e);
    }
    int l = 1, r = n, ans;
    while(l<=r) {
        int m = l+(r-l)/2;
        if(psbl(m)) {
            ans = m;
            l = m+1;
        } else r = m-1;
    }
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin>>t;cin.clear();
    while(t--) {
        cout<<solve()<<endl;
        // solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

