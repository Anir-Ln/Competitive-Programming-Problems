/*
Mohamed Lahyane (Anir_Ln)
2021-11-10
11:12:07
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<bool> visited(150002, false);
bool ans = true;
int len = 0;

void dfs(int node, vv32& adj, int deg) {
    len++;
    if(adj[node].size() != deg) {
        ans = false;
        return;
    }

    for(int nei : adj[node]) {
        if(visited[nei])
            continue;
        visited[nei] = true;
        dfs(nei, adj, deg);
        if(!ans)
            return;
    }
}


void solve(){
    int n, m;
    cin >> n >> m;
    vv32 adj(n+1);
    int a, b;
    
    forn(i, m) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }    

    forsn(i, 1,  n+1) {
        if(!visited[i]) {
            visited[i] = true;
            dfs(i, adj, adj[i].size());
            if(adj[i].size() != len - 1)
                ans = false;
            if(!ans)
                break;
            len = 0;
        }
    }

    cout << (ans ? "YES" : "NO");
}


int main()
{
    c_p_c();
    solve();
    return 0;
}