/*
Mohamed Lahyane (Anir_Ln)
2021-09-26
15:36:15
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


void print_r(vector<pair<int, double> > g){
    for(auto item: g)
        cout << item.ff+1 << sp <<fixed <<setprecision(2)<< item.ss << ln;
}

bool cmp(pair<int, double> a, pair<int, double> b){
    if(a.ss == b.ss)
        return (a.ff < b.ff);
    return a.ss > b.ss;
}

void solve(){
    int n, t1, t2, k;
    cin >> n >> t1 >> t2 >> k;

    vector<pair<int, double> > g(n);
    int a, b;
    double p1, p2;
    forn(i, n){
        cin >> a >> b;
        p1 = (double)t1*a*(1 - (double)k/100) + t2*b;
        p2 = (double)t1*b*(1 - (double)k/100) + t2*a;
        g[i] = (mp(i, max(p1, p2)));
    }

    sort(all(g), cmp);
    print_r(g);

}


int main()
{
    c_p_c();
    solve();
    return 0;
}