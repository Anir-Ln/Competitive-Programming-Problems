/*
Mohamed Lahyane (Anir_Ln)
2021-10-19
11:26:47
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

const int m = 1073741824;

ll d(int a) {
    ll count = 0;
    for(int i=1; i*i<=a; i++) {
        if(a%i==0) {
            if(a/i != i)
                count++;
            count++;
        }
    }
    return count;
}


void solve(){
    int a, b, c;
    cin >> a >> b >> c;

    v32 dp(a*b*c + 1, -1);
    ll ans = 0;
    
    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            for(int k=1; k<=c; k++) {
                int &a = dp[i*j*k];
                if(a != -1) { 
                    ans += a;
                }
                else {
                    ans += a = d(i*j*k);
                }
            }
        }
    }
    cout << ans << ln;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}