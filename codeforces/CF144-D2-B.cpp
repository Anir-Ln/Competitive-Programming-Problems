/*
Mohamed Lahyane (Anir_Ln)
2021-10-10
22:23:41
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

bool dist(int x1, int y1, int x2, int y2, int r) {
    if((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) <= r*r)
        return true;
    return false;
}


void solve(){
    p32 p1, p2;
    cin >> p1.ff >> p1.ss >> p2.ff >> p2.ss;
    if(p1.ss < p2.ss){
        int diff = p2.ss - p1.ss;
        p1.ss += diff;
        p2.ss -= diff;
    }

    if(p2.ff < p1.ff) {
        int diff = p1.ff - p2.ff;
        p1.ff -= diff;
        p2.ff += diff;
    }
    int n;
    cin >> n;
    map<p32, bool> yes;
    int r;
    p32 r_pos;
    forn(i, n){
        cin >> r_pos.ff >> r_pos.ss >> r;
        for(int y = p2.ss; y <= p1.ss; y++){
            if(dist(p1.ff, y, r_pos.ff, r_pos.ss, r)){
                yes[{p1.ff, y}] = true;
            }
            if(dist(p2.ff, y, r_pos.ff, r_pos.ss, r)){
                yes[{p2.ff, y}] = true;
            }
        }

        for(int x = p1.ff + 1; x < p2.ff ; x++){
            if(dist(x, p1.ss, r_pos.ff, r_pos.ss, r)){
                yes[{x, p1.ss}] = true;
            }
            if(dist(x, p2.ss, r_pos.ff, r_pos.ss, r)){
                yes[{x, p2.ss}] = true;
            }
        }
    }
    
    // for(auto p: yes)
    //     cout << p.ff.ff << sp << p.ff.ss << ln;
    cout << 2*(p1.ss - p2.ss + 1) + 2*(p2.ff - p1.ff - 1) - yes.size() << ln;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}