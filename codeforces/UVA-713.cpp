/*
Mohamed Lahyane (Anir_Ln)
2021-09-19
10:23:18
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
//#include <cmath>
#include <string>
#include <vector>
//#include <map>
//#include <unordered_map>
//#include <stack>
//#include <iomanip>
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



void solve(){
    string a, b, na, nb;
    cin >> a;
    cin >> b;

    int i = sz(a) - 1;
    while(i>=0 && a[i] == '0'){
        i--;
    }
    while(i>=0){
        na.pb(a[i]);
        i--;
    }

    i = sz(b) - 1;
    while(i>=0 && b[i] == '0'){
        i--;
    }
    while(i>=0){
        nb.pb(b[i]);
        i--;
    }

    i = sz(na) - 1;
    int j = sz(nb) - 1;
    string res;
    int r = 0;
    int val;
    while(i >= 0 || j >= 0){
        if(i < 0)
            val = (nb[j] - '0') + r;
        else if(j < 0)
            val = (na[i] - '0') + r;
        else
            val = (na[i] - '0') + (nb[j] - '0') + r;

        if(val <= 9){
            res.pb((char)(val + '0'));
            r = 0;
        }
        else {
            res.pb((char)(val%10 + '0'));
            r = val/10;
        }
        i--;
        j--;
    }

    if(r)
        res.pb((char) (r + '0'));


    i = 0;
    int len = sz(res);
    while(i<len && res[i] == '0')
        i++;
    
    for(i; i<len; i++)  
        cout << res[i];
    cout << ln;
}

int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=0; it<t; it++) {
        solve();
    }
    return 0;
}