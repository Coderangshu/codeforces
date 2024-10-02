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
#define forenum(index, value, container) for (int index = 0, _size = container.size(); index < _size; ++index) for (auto& value = container[index]; index < _size; index = _size)
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

// GET UNORDERED MAP AS INPUT WITH FREQUENCY OF EACH NUMBER
unm<int,int> getIntsinUM(int n) {
    unm<int,int> um;
    forl(i,n) {
        int e;cin>>e;
        um[e]++;
    }
    return um;
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

auto solve() {
    unm sticks = getIntsinUM(6);
    if(sz(sticks)>3) return "Alien";
    int leg = 0, body = 0, head = 0;
    fora(i,sticks) {
        // cerr<<i.x<<" "<<i.y<<endl;
        // if(i.y!=4 and i.y!=1 and i.y!=2 and i.y!=6) return "Alien";
        // if(i.y==6) return "Elephant";
        // if(i.y==4) continue;
        // if(i.y==1) continue;
        // else return "Elephant";
        if(i.y==6) {
            return "Elephant";
        } else if(i.y==5) {
            leg = i.x;
            if(!head) head = i.x;
            else {
                int temp = head;
                head = min(i.x,head);
                body = max(i.x,temp);
            }
        } else if(i.y==4) {
            leg = i.x;
        } else if(i.y==3) {
            return "Alien";
        } else if(i.y==2) {
            head = body = i.x;
        } else if(i.y==1) {
            if(!head) head = i.x;
            else {
                int temp = head;
                head = min(head,i.x);
                body = max(temp,i.x);
            }
        }
    }
    if(!head or !body or !leg) return "Alien";
    if(head!=body) return "Bear";
    return "Elephant";
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin>>t;cin.clear()
    while(t--) {
        cout<<solve()<<endl;
        // solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << "\n";
}

