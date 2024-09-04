#include<bits/stdc++.h>
using namespace std;

#define int ll
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define forl(i,n) for(int i = 0; i < int(n); i++)
#define forr(i,n) for(int i = n-1; i > -1; i--)
#define fore(l, r) for(int i = int(l); i <= int(r); i++)
#define fora(v,arr) for(auto v:arr)
#define unm unordered_map
#define uns unordered_set
#define INT_MAX LLONG_MAX
#define INT_MIN LLONG_MIN

using ll = long long;
typedef long double ld;
using pii = pair<int, int>;
typedef vector<long long> vi;

// GET INTEGER ARRAY AS INPUT OF SIZE N
vi getInts(int n) {
    vi arr(n);
    forl(i,n) cin>>arr[i];
    return arr;
}

// GET A STRING WITH SPACE AS A SINGLE STRING IN INPUT
string getStr() {
    string strIp;
    getline(cin,strIp);
    return strIp;
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

bool compare (pair<char,int> p1, pair<char,int> p2) { 
    if(p1.y==p2.y) return p1.y > p2.y; 
    else return p1.x<p1.y;
} 

auto solve() {
    int n;cin>>n;
    string s;cin>>s;
    if(n==1) return 1ll;
    vector<char> o,e;
    unm<char,int> op,ep;
    vector<pair<char,int>> ov,ev;
    int maxo = INT_MIN, maxe = INT_MIN;
    ep.clear();
    op.clear();
    forl(i,n) {
        if(i%2==0) {
            e.pb(s[i]);
            ep[s[i]]++;
            maxe = max(maxe,ep[s[i]]);
        } else {
            o.pb(s[i]);
            op[s[i]]++;
            maxo = max(maxo,ep[s[i]]);
        }
    }
    int se = sz(ep), so = sz(op);
    fora(i,op) cout<<i.x<<" "<<i.y<<"; ";
    cout<<endl;
    fora(i,ep) cout<<i.x<<" "<<i.y<<"; ";
    cout<<endl;
    cout<<se<<" "<<so<<endl;
    if(se==1 and so==1) return 0ll;
    int ans = 0;
    if(n%2!=0) {
        ans = 1;
        if(se%2!=0) se--;
        else so--;
    }
    maxo = (maxo==INT_MIN)?0:maxo;
    maxe = (maxe==INT_MIN)?0:maxe;
    // cout<<maxo<<" "<<maxe<<"  dlksjfsdlkf"<<endl;
    ans += se-maxe+so-maxo;
    return ans;
    // copy(all(op), back_inserter(ov)); 
    // copy(all(ep), back_inserter(ev));
    // sort(all(ov), compare);
    // sort(all(ev), compare);
    
    // cout<<"ODD"<<endl;
    // fora(i,o) cout<<i<<" ";
    // cout<<endl;
    // cout<<"EVEN"<<endl;
    // fora(i,e) cout<<i<<" ";
    // cout<<endl;
    // int on = sz(o), en = sz(e);
    // if((on%2)^(en%2)) {

    // }
    // return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin>>t;
    while(t--) {
        cout<<solve()<<endl;
        // solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}