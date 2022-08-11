/*
Mohamed Lahyane (Anir_Ln)
2021-10-30
21:30:19
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

vv32 adj(52);
vector<bool> vis(52, false);

// int dfs(int a) {
//     if(adj[a].size() == 0)
//         return 0;

//     vis[a] = true;
//     int mx = 0;
//     for(int nei: adj[a]) {
//         if(!vis[nei]) {
//             vis[nei] = true;
//             mx = max(mx, 1 + dfs(nei));
//             // cout << nei << " - " << mx << ln;
//         }
//         vis[nei] = false;
//     }

//     return mx;
// }


int dfs(int i) {
    vis[i] = true;
    int res = 0;
    for(int x: adj[i]){
        if(vis[x])
            continue;
        vis[x] = true;
        res += 1 + dfs(x);
    }
    return res;
}


void solve(){
    int n, m;
    cin >> n >> m;
    int a, b;
    if(m == 0) {
        cout << 1 << ln;
        return;
    }
    forn(i, m) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int count = 0;
    for(int i = 1; i<=n; i++) {
        if(adj[i].size() != 0 && !vis[i]) {
            count += dfs(i) ;
        }
    }
    ll ans;
    // cout << count << ln;
    // if(count == n)
    //     ans = pow(2, n-1);
    // else
    //     ans = pow(2, count-1);
    ans = pow(2, count);
    cout << ans << ln;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}