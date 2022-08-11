/*
Mohamed Lahyane (Anir_Ln)
2021-11-09
23:37:54
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
    int n, k, l, r, sll, sk;
    cin >> n >> k >> l >> r >> sll >> sk;
    v32 ans(n, l);
    
    int less = sll - sk - (n-k)*l;
    int mid = less/(n-k);
    int mx = mid;
    for(int i=k; i<n && less; i++) {
        if(i==n-1) {
            ans[i] += less;
            mx = max(less, mx);
            continue;
        }
        mid = less/(n-i);
        ans[i] += min(mid, less);
        less -= mid;
    }

    int rest = sll - n*l;
    int rest_k = sk - k*l;

    mid = rest_k/k;
    
    for(int i=0; i<k && rest_k; i++) {
        mid = rest_k/(k-i);
        ans[i] += min(rest_k, mid);
        // mn = min(mn, mid);
        rest_k -= mid;
    }
    // for(i=k; i<n && rest; i++) {
    //     ans[i] += min(rest, mn);
    //     rest -= min(rest, mn);
    // }

    for(int a : ans)
        cout << a << sp;

    // int s = 0, s_ = 0;
    // for(int i=0; i<n; i++) {
    //     if(i<k)
    //         s_ += ans[i];
    //     s += ans[i];
    // }
    // cout << s << sp << s_;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}