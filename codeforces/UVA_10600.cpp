/*
Mohamed Lahyane (Anir_Ln)
2021-11-20
20:35:41
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
#include <limits>
 
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

// struct node
// {
//     int a, b, c;
//     bool operator() (node& a, node& b) {
//         return a.c > b.c;
//     }
// };

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
    void reset() {
        edges = 0;
        int n = id.size();
        forn(i, n) {
            id[i] = i;
            size[i] = 1;
        }
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

void solve(){
    int n, m;
    cin >> n >> m;
    // priority_queue<node, vector<node>, node> pq;
    vector<pair<int, p32>> v;
    int a, b, c;
    forn(i, m)
    {
        cin >> a >> b >> c;
        v.pb({c, {a-1, b-1}});        
    }
    sort(all(v));

    UnionFind uf(n);
    int cost1 = 0;
    vector<bool> chosen(m);
    for(int i=0; i<m && uf.edges != n-1; i++) {
        if(uf.unify(v[i].second.first, v[i].second.second)) {
            cost1 += v[i].first;
            chosen[i] = true;
        }
    }

    int cost2 = (int)INF;
    for(int j=0; j<m; j++) {
        if(chosen[j]) {
            uf.reset();
            int cost_tmp = 0;
            for(int i=0; i<m && uf.edges != n-1; i++) {
                if(j == i)
                    continue;
                if(uf.unify(v[i].second.first, v[i].second.second)) {
                    cost_tmp += v[i].first;
                }
            }
            // make sure is mst
            if(uf.edges == n-1)
                cost2 = min(cost2, cost_tmp);
        }
    }

    cout << cost1 << sp << cost2 << ln;
}


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