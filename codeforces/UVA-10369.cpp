/*
Mohamed Lahyane (Anir_Ln)
2021-11-21
20:45:14
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
//#include <limits>
 
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

struct node {
    int x, y; 
    double dist;
    
    bool operator() (node& a, node& b) {
        return a.dist > b.dist;
    }

    // bool operator > (const node& b) {
    //     return this->dist > b.dist;
    // }
};

void solve(){
    int s, n;
    cin >> s >> n;

    vp32 pos(n);
    forn(i, n) {
        cin >> pos[i].ff >> pos[i].ss;
    }
    priority_queue<node, vector<node>, node> pq;
    forn(i, n) {
        forsn(j, i+1, n) { 
            pq.push({i, j, sqrt((pos[i].ff - pos[j].ff)*(pos[i].ff - pos[j].ff) + (pos[i].ss - pos[j].ss)*(pos[i].ss - pos[j].ss))});
        }
    }
    
    UnionFind uf(n);
    vector<node> mst(n-1);
    int index = n-2;
    while(!pq.empty() && uf.edges != n-1) {
        node curr = pq.top();
        pq.pop();

        if(uf.unify(curr.x, curr.y)) {
            mst[index--] = curr;
        }
    }

    // sort(all(mst), node());

    cout << fixed << setprecision(2);
    cout << mst[s-1].dist << ln;
    // forn(i, n-1){
        
    //     // if(uf.id[mst[i].x] != -1)
    //     //     uf.id[mst[i].x] = -1;s--;
    //     // if(uf.id[mst[i].y] != -1)
    //     //     uf.id[mst[i].y] = -1;s--;

    //     // if(s<0)
    //     // {
    //     //     cout << sqrt(mst[i].dist) << ln;
    //     //     return;
    //     // }

    //     cout << mst[i].x << sp << mst[i].y << " -> " << sqrt(mst[i].dist) << ln;
    // }
}

// first find the mst, sort the edges of the mst by their weights, the first s-1 edges (the longuest s-1 edges) will be reachable using satellites (not necessarly having satellites in both nodes of the edge) but it's garanteed that the D disatance is another the longest edge that is not part of the s-1 longest edges, which means, it's the s'th edge e.i mst[s-1] (0-indexed),  
int main()
{
    c_p_c();
    ll t;
    cin >> t;
    for(int it=0; it<t; it++) {
        // cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}