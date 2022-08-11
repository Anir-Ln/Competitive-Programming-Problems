/*
Mohamed Lahyane (Anir_Ln)
2021-10-19
23:26:56
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

int memo[10001];
vector<bool> visited(10001);

int ans(int n, int m) {
    if(n > 10000 || n == 0)
        return 10000;
    if(n == m)
        return 0;
    int &res = memo[n];

    // it can be already be visited but not yet found an answer (cycle)
    if(visited[n]) {
        // if it is a cycle
        if(res == -1) 
            return 10000;
        return res;
    }
    visited[n] = true;
    return res = 1 + min(ans(n-1, m), ans(2*n, m));
}

void solve(){
    int n, m;
    cin >> n >> m;
    fill_n(memo, sizeof memo / sizeof *memo, -1);
    cout << ans(n, m);
}


int main()
{
    c_p_c();
    solve();
    return 0;
}