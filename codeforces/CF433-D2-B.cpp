/*
Mohamed Lahyane (Anir_Ln)
2021-09-19
17:06:59
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
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
void c_p_c()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}




int main()
{
    fast_cin();
    int n;
    cin >> n;
    int arr[n];
    forn(i, n){
        cin >> arr[i];
    }

    ll pre1[n];
    pre1[0] = arr[0];
    forsn(i, 1, n){
        pre1[i] = pre1[i-1] + arr[i];
    }
    sort(arr, arr+n);
    ll pre2[n];
    pre2[0] = arr[0];
    forsn(i, 1, n){
        pre2[i] = pre2[i-1] + arr[i];
    }
    int m;
    int t, l, r;
    ll res;
    cin >> m;
    while(m--){
        cin >> t >> l >> r;
        if(t == 1){
            res = pre1[r-1]; 
            if(l > 1)
                res -= pre1[l - 2];
        } else {
            res = pre2[r-1]; 
            if(l > 1)
                res -= pre2[l - 2];
        }

        cout << res << ln;
    }




    return 0;
}