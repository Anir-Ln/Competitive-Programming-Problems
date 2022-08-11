/*
Mohamed Lahyane (Anir_Ln)
2021-11-19
21:49:53
*/
#include <iostream>
//#include <complex>
#include <queue>
//#include <set>
//#include <unordered_set>
//#include <list>
//#include <chrono>
//#include <random>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
//#include <unordered_map>
//#include <stack>
#include <iomanip>
#include <fstream>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = (ll) 1e9 + 7;
double eps = 1e-12;
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define ln "\n"
#define sp ' '
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define INF 2e18
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
void c_p_c()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
struct node {
    int x, y;
    double dist;

    bool operator()(node& a, node& b) {
        // for pq return is a > b
        return a.dist > b.dist;
    }
};
class UnionFind {
    public:
    v32 size;
    v32 id;
    int edges;

    UnionFind(int n) {
        size = v32(n);
        id = v32(n);
        forn(i, n){
            id[i] = i;
            size[i] = 1;
        }
        edges = 0;
    }

    int find(int p) {
        int root = p;
        while(root != id[root])
            root = id[root];
        
        // path compression
        while(root != p) {
            int nxt = id[p];
            id[p] = root;
            p = nxt;
        }
        return root;
    }

    bool unify(int p, int q) {
        p = find(p);
        q = find(q);
        if(p == q)
            return false;
        if(size[p] < size[q]) {
            size[q] += size[p];
            id[p] = q;
        } else {
            size[p] += size[q];
            id[q] = p;
        }
        edges++;
        return true;
    }

};

double getDist(p32& p1, p32& p2) {
    return (double) (p1.ff - p2.ff)*(p1.ff - p2.ff) + (p1.ss - p2.ss)*(p1.ss - p2.ss);
}

void solve(){
    int n, m;
    cin >> n;
    vp32 towns(n);
    priority_queue<node, vector<node>, node> pq;
    int x, y;
    forn(i, n) {
        cin >> towns[i].ff >> towns[i].ss;
    }
    forn(i, n) {
        forsn(j, i+1, n) {
            pq.push({i, j, getDist(towns[i], towns[j])});
        }
    }
    cin >> m;
    
    // if(m == n-1)
    // {
    //     cout << "No new highways need" << ln;
    //     return;
    // }

    UnionFind uf(n);

    if(m) {
        vp32 ex(m);
        forn(i, m) {
            cin >> ex[i].ff >> ex[i].ss;
            ex[i].ff--;
            ex[i].ss--;
            uf.unify(ex[i].ff, ex[i].ss);
        }
    }



    int index = 0;
    while(!pq.empty() && uf.edges != n-1) {
        node curr = pq.top();
        pq.pop();
        if(uf.unify(curr.x, curr.y))
            cout << curr.x+1 << sp << curr.y+1 << ln;index++;
    }
    if(!index)
        cout << "No new highways need" << ln;
}


int main()
{
    c_p_c();
    ll t;
    cin >> t;
    for(int it=0; it<t; it++) {
        // cout << "Case #" << it+1 << ": ";
        solve();
        if(it != t-1)
            cout << ln; 
    }
    return 0;
}