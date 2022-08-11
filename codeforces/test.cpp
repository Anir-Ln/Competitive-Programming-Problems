/*
Mohamed Lahyane (Anir_Ln)
2021-09-21
13:49:54
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <iostream>
//#include <complex>
//#include <queue>
//#include <set>
//#include <unordered_set>
//#include <list>
//#include <chrono>
//#include <random>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
//#include <map>
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

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


char c;
int n, m;

int dfs(int i, int j, vector<vector<bool> > &visited, vector<vector<char> > &s){

    if(i > n-1 || i < 0)
        return 0;
    if(j > m-1 || j < 0)
        j = (j + m)%m;

    if(s[i][j] != c || visited[i][j])
        return 0;

    visited[i][j] = true;
    
    return 1 + dfs(i+1, j, visited, s) + dfs(i, j+1, visited, s) + dfs(i-1, j, visited, s) + dfs(i, j-1, visited, s);
}


void solve(){
    vector<vector<char> > s(n, vector<char> (m));
    forn(i, n)
        forn(j, m)
            cin >> s[i][j];
    int px, py;
    cin >> px >> py;
    c = s[px][py];

    vector<vector<bool> > visited(n, vector<bool> (m, false));

    int k = dfs(px, py, visited, s);
    // cout << k << ln;
    
    int mx = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i][j] == c)
                mx = max(mx, dfs(i, j, visited, s));
        }
    }

    cout << mx << ln;
}


int function(int a, int b) {
  for (int i=0; i<n; i++) {
    if (a == b){
      a++;
      b--;
    }
    
  }
} 


int main()
{
    c_p_c();

    while(cin >> n >> m)
        solve();
    return 0;
}
