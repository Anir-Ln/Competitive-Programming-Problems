/*
Mohamed Lahyane (Anir_Ln)
2021-09-29
19:10:52
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

ll *x;
ll *h;
int n;
ll memo[100001][2];
// last = 1 -> h[i-1]
// lst = 0 -> 0
ll trees(int i, int last){
    if(i == n-1)
        return 0;

    ll &res = memo[i][last];
    if(res != -1)
        return res;

    bool left, right;

    if(last)
        last = h[i-1];

    left = x[i-1] + last < x[i] - h[i];
    right = x[i+1] > x[i] + h[i];

    if(left) {
        return res = 1 + trees(i+1, 0);
    }   

    if(right) {
        return res = max(trees(i+1, 0), 1 + trees(i+1, 1));
    }

    return res = trees(i+1, 0);
}

// greedy:
// always cut to the left if possible
// if left is impossible take the max of right or not cutting it
// if both left and right are impossible, skip the tree
void solve(){
    cin >> n;
    ll  *xi = new ll[n];
    ll *hi = new ll[n];
    forn(i, n)
        cin >> xi[i] >> hi[i];
    x = xi;
    h = hi;

    forn(i, 100001)
        forn(j, 2)
            memo[i][j] = -1;
    if(n == 1)
        cout << 1 << ln;
    else if(n == 2)
        cout << 2 << ln; 
    else 
        cout << 2 + trees(1, 0) << ln;

    delete[] xi;
    delete[] hi;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}