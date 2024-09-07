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

char identifyNum(string s) {
    int i = 0, j = 1;
    bool allEqual = true, decreasing = true;
    while (i<8 and j<8) {
        if(s[j]=='-') j++;
        if(s[i]<=s[j]) decreasing = false;
        if(s[i]!=s[j]) allEqual = false;
        i = j;
        j++;
        if(!allEqual and !decreasing) break;
    }
    if(allEqual) return 'e';
    if(decreasing) return 'd';
    return 'n';
}

auto solve() {
    int n;cin>>n;
    vi nopn(n);
    vector<string> cname, pname, gname;
    int cmax = INT_MIN, pmax = INT_MIN, gmax = INT_MIN;
    forl(i,n) {
        int sn, cn = 0, pn = 0, gn = 0;cin>>sn;
        string name;cin>>name;
        while(sn--) {
            string phoneNum;cin>>phoneNum;
            char returnVal = identifyNum(phoneNum);
            if(returnVal=='e') cn++;
            else if(returnVal=='d') pn++;
            else gn++;
        }
        if(cn>cmax) {
            cmax = cn;
            cname.clear();
            cname.pb(name);
        } else if(cn==cmax) cname.pb(name);
        if(pn>pmax) {
            pmax = pn;
            pname.clear();
            pname.pb(name);
        } else if(pn==pmax) pname.pb(name);
        if(gn>gmax) {
            gmax = gn;
            gname.clear();
            gname.pb(name);
        } else if(gn==gmax) gname.pb(name);
        
        
        
        // cout<<name<<" "<<cn<<" "<<pn<<" "<<gn<<endl;
        // fora(j,cname) cout<<j<<" ";
        // cout<<endl;
        // fora(j,pname) cout<<j<<" ";
        // cout<<endl;
        // fora(j,gname) cout<<j<<" ";
        // cout<<endl;
    }
    cout<<"If you want to call a taxi, you should call: ";
    forl(i,sz(cname)) {
        if(i!=sz(cname)-1) cout<<cname[i]<<", ";
        else cout<<cname[i]<<"."<<endl;
    }
    cout<<"If you want to order a pizza, you should call: ";
    forl(i,sz(pname)) {
        if(i!=sz(pname)-1) cout<<pname[i]<<", ";
        else cout<<pname[i]<<"."<<endl;
    }
    cout<<"If you want to go to a cafe with a wonderful girl, you should call: ";
    forl(i,sz(gname)) {
        if(i!=sz(gname)-1) cout<<gname[i]<<", ";
        else cout<<gname[i]<<"."<<endl;
    }
    cname.clear();
    pname.clear();
    gname.clear();
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin>>t;cin.clear()
    while(t--) {
        // cout<<solve()<<endl;
        solve();
    }
    // cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

