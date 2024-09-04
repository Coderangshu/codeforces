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

bool isPerfectSquare(long long x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {

        long long sr = sqrt(x);
        
        // if product of square root 
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}

auto solve() {
    int n;cin>>n;
    string s;cin>>s;
    if(!isPerfectSquare(n)) return "No";
    int sr = sqrt(n);
    // cout<<"sr "<<sr<<endl;
    forl(i,sr) {
        // cout<<i<<" "<<s[i]<<endl;
        if(s[i]!='1') return "No";
    }
    int i = n-1;
    int ts = sr;
    while(ts--) if(s[i--]!='1') return "No";
    s = s.substr(sr,n-2*sr);
    if(s.length()>0) {
    // cout<<s<<endl;
        ts = sr-2;
        int j = 0;
        while(ts--) {
            i = 0;
            int tss = sr;
            while(tss--) {
                // cout<<i<<" "<<j<<" "<<s[i+j]<<endl;
                if((i==0 or i%sr==sr-1)) {
                    if(s[i+j]!='1') return "No";
                } else if (s[i+j]!='0') return "No";
                i++;
            }
            j += sr;
        }
    }
    return "Yes";
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

