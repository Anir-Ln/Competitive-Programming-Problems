/*
Mohamed Lahyane (Anir_Ln)
2021-10-30
19:06:57
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
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
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
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
}

vector<vp32> adj(104);
vector<bool> vis(105, false);



bool dfs(int a, int b, int c) {
    if(a == b) {
        return true;
    }
    vis[a] = true;
    bool res = false;
    for(p32 p : adj[a]) {
        if(p.ss == c && !vis[p.ff]) {
                vis[p.ff] = true;
                if(dfs(p.ff, b, c))
                    return true;
        }
    }

    return false;
}


void solve(){
    int n, m;
    cin >> n >> m;
    int a, b, c;
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    int q;
    cin >> q;
    bool co[104];
    int count = 0;
    while(q--) {
        cin >> a >> b;
        fill_n(co, sizeof(co), false);
        for(p32 p: adj[a]) {
            if(co[p.ss]) 
                continue;
            co[p.ss] = 1;
            count += dfs(a, b, p.ss);
            forn(i, 105)
                vis[i] = false;
        }
        cout << count << ln;
        count = 0;
    }
}


int main()
{
    c_p_c();
    solve();
    return 0;
}