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

bool check(double a, double b, double c) {
    if(a>0 and b>0 and c>0 and a==int(a) and b*b+a*a==c*c)
        return true;
    return false;
}

void print(int a, int b) {
    cout<<a<<" "<<b<<endl;
    return;
}

auto solve() {
    int n;cin>>n;
    if(n<3) cout<<-1<<endl;
    else if(n&1) cout<<(sqr(n)-1)/2<<" "<<(sqr(n)+1)/2<<endl;
    else cout<<sqr(n/2)-1<<" "<<sqr(n/2)+1<<endl;
    // double nb2 = n/2.0, n2b2 = n*n/2.0;
    // // cerr<<nb2<<" "<<n2b2<<endl;
    // if(n%2==0) {
    //     double a = sqrt(n-1)*2, b = n-2, c = n;
    //     if(check(a,b,c)) {
    //         print(a,b);
    //         return;
    //     }
    //     a = sqrt((n+0.5)*2.0), b = n, c = n+1;
    //     int d = int(a), e = int(b), f = int(c);
    //     // cerr<<d<<" "<<e<<" "<<f<<endl;
    //     if(check(a,b,c)) {
    //         print(a,c);
    //         return;
    //     }
    //     a = sqrt(n+1)*2, b = n, c = n+2;
    //     d = int(a), e = int(b), f = int(c);
    //     // cerr<<d<<" "<<e<<" "<<f<<endl;
    //     if(check(a,b,c)) {
    //         print(a,c);
    //         return;
    //     } 
    //     a = n, b = nb2*nb2-1, c = nb2*nb2+1;
    //     if(check(a,b,c)) {
    //         print(b,c);
    //         return;
    //     }
    //     else cout<<-1<<endl;
    // } else {
    //     double a = sqrt((n-0.5)*2), b = n-1, c = n;
    //     // cerr<<a<<" "<<b<<" "<<c<<endl;
    //     if(check(a,b,c)) {
    //         print(a,b);
    //         return;
    //     }
    //     a = n, b = n2b2-0.5, c = n2b2+0.5;
    //     // cerr<<a<<" "<<b<<" "<<c<<endl;
    //     if(check(a,b,c)) {
    //         print(b,c);
    //         return;
    //     }
    //     else cout<<-1<<endl;
    // }
    // return;
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

