/*
Mohamed Lahyane (Anir_Ln)
2021-11-20
23:00:32
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
// #include <map>
#include <unordered_map>
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
        // if already in the same network, print the size of it
        if(p == q){
            cout << max(size[p], size[q]) << ln;
            return false;
        }
        // else, merge the two networks, and print the new size
        if(size[p] < size[q]) {
            size[q] += size[p];
            id[p] = q;
            cout << size[q] << ln;
        } else {
            size[p] += size[q];
            id[q] = p;
            cout << size[p] << ln;
        }
        edges++;
        return true;
    }

};

void solve(){
    int e;
    cin >> e;
    UnionFind uf(e+1);
    unordered_map<string, int> hash;
    int index = 0;
    string a, b;
    int f1, f2;
    // hash the names into integers
    forn(i, e) {
        cin >> a >> b;
        if(hash.find(a) == hash.end())
            hash[a] = f1 = index++;
        else 
            f1 = hash[a];
        if(hash.find(b) == hash.end())
            hash[b] = f2 = index++;
        else 
            f2 = hash[b];
        // unifies and prints the size of the network
        uf.unify(f1, f2);
        // cout << uf.size[f1] << ln;
    }
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