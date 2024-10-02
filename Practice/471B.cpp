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

auto solve() {
    int n;cin>>n;
    map<int,vi> mp;
    forl(i,n) {
        int e;cin>>e;
        mp[e].pb(i);
    }
    int possibilities = 0;
    fora(i,mp) {
        int ln = len(i.y);
        if(ln>=2) possibilities++;
        if(ln>=3) {
            possibilities = 100;
            break;
        }
    }
    if(possibilities<2) {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    int cnt = 0;
    fora(i,mp) {
        vi a = i.y;
        // cerr<<i.x<<endl;
        // fora(j,a) cerr<<j<<" ";
        // cerr<<endl;
        fora(j,a) cout<<j+1<<" ";
        if(len(a)>1 and cnt==0) {
            next_permutation(all(a));
            mp[i.x] = a;
            cnt++;
        }
        // fora(j,a) cerr<<j<<" ";
        // cerr<<endl;
    }
    // cerr<<endl<<endl;
    cout<<endl;
    cnt = 0;
    fora(i,mp) {
        vi a = i.y;
        // cerr<<i.x<<endl;
        // fora(j,a) cerr<<j<<" ";
        // cerr<<endl;
        fora(j,a) cout<<j+1<<" ";
        if(len(a)>1) {
            if(cnt>=1 or len(a)>2) {
                next_permutation(all(a));
                mp[i.x] = a;
            } else cnt++;
        }
        // fora(j,a) cerr<<j<<" ";
        // cerr<<endl;
    }
    cout<<endl;
    fora(i,mp) fora(j,i.y) cout<<j+1<<" ";
    cout<<endl;
    return;
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

