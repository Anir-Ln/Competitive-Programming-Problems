/*
Mohamed Lahyane (Anir_Ln)
2021-09-25
18:43:40
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



void solve(){
    int n, m, k, tmp;
    v32 x, y, z;
    cin >> n;
    forn(i, n){
        cin >> tmp;
        x.pb(tmp);
    }
    cin >> m;
    forn(i, m){
        cin >> tmp;
        y.pb(tmp);
    }
    cin >> k;
    forn(i, k){
        cin >> tmp;
        z.pb(tmp);
    }

    int a, b;
    cin >> a >> b;

    sort(all(x));
    sort(all(y));
    sort(all(z));

    double res = (double)x[n-1] / sqrt(1 + (double)(a*z[0])/((b*y[m-1])));
    cout << fixed << setprecision(12) << res << ln;
        
}


int main()
{
    c_p_c();
    solve();
    return 0;
}