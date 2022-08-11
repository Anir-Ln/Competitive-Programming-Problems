/*
Mohamed Lahyane (Anir_Ln)
2021-09-25
23:33:53
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

// make sure constraints are not violated  (1,1) <= curr <= (n, m)
// calculate the maximum number of steps towards direction dir without violating the constraints;
int step(p32 &curr, p32 dir,  int n, int m){
    int f = 0, s = 0;
    if(dir.ff > 0){
        f = (n - curr.ff)/dir.ff;
    } else if(dir.ff < 0) {
        f = (curr.ff - 1)/dir.ff;
    }
    
    if(dir.ss > 0){
        s = (m - curr.ss)/dir.ss;
    } else if(dir.ss < 0) {
        s = (curr.ss - 1)/dir.ss;
    }
    int mn = min(abs(s), abs(f));

    // if dir.ff == 0, we can go as much as want in ff axis => s
    if(dir.ff == 0)
        mn = abs(s);
    if(dir.ss == 0)
        mn = abs(f);
    curr = {curr.ff + mn*dir.ff, curr.ss + mn*dir.ss};  

    return mn;
}

void solve(){
    int n, m;
    p32 curr;
    // p32 b = {1, 1};
    cin >> n >> m;
    cin >> curr.ff >> curr.ss;

    int k;
    ll count = 0;
    p32 dir;
    cin >> k;
    while(k--){
        cin >> dir.ff >> dir.ss;
        count += (ll)step(curr, dir, n , m);
        // cout << curr.ff << ", " << curr.ss << ln;
    }
    cout << count << ln;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}