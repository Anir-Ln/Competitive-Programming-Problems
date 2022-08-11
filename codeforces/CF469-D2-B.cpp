/*
Mohamed Lahyane (Anir_Ln)
2021-09-24
21:41:59
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

int cmp(p32 z_ran, p32 x_ran){
    if(z_ran.ff > x_ran.ss)
        return -1;
    if(x_ran.ff > z_ran.ss)
        return 1;
    return 0;
}

void solve(){
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    vp32 z_range(p);
    vp32 x_range(q);

    forn(i, p)  cin >> z_range[i].ff >> z_range[i].ss;
    forn(i, q)  cin >> x_range[i].ff >> x_range[i].ss;

    int x, z;
    int count = 0;
    int res;
    forsn(t, l, r+1){
        x = 0;
        z = 0;
        // konwing that the to vectors are sorted, the same approach as similar to sorting to sorting arrays -> O(p + q) -> overall O((r-l+1)*(p+q))
        while(x < q && z < p){
            res = cmp(z_range[z], {x_range[x].ff + t, x_range[x].ss + t});
            if(res == 1){
                z++;
            } else if(res == -1) {
                x++;
            } else {
                count++;
                break;
            }
        }
    }


    cout << count << ln;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}