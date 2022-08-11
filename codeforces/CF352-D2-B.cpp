/*
Mohamed Lahyane (Anir_Ln)
2021-10-10
21:10:16
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


v32 occ(100001);
vp32 ind(100001);
void solve(){
    int n, k;
    cin >> n;
    
    v32 arr(n);

    forn(i, n)
    {
        cin >> arr[i];
        occ[arr[i]]++;
        if(occ[arr[i]] == 1) {
            ind[arr[i]].ff = i;
        } else if (occ[arr[i]] == 2) {
            ind[arr[i]].ss = i;
        }
    }   
    vp32 res;
    forn(i, 100001){
        if(occ[i] == 0)
            continue;
        if(occ[i] == 1) {
            res.pb({i, 0});
            continue;
        }
        if(occ[i] == 2) {
            res.pb({i, ind[i].ss - ind[i].ff});
            continue;
        }

        k = ind[i].ss - ind[i].ff;
        int count = 0;
        for(int j = ind[i].ff; j<n; j+=k){
            if(count == occ[i])
                break;
            if(arr[j] != i) {
                count = -1;
                break;
            }
            count++;
        }
        if(count == occ[i])
            res.pb({i, k});
    }

    cout << res.size() << ln;
    for(auto p : res) {
        cout << p.ff << sp << p.ss << ln;
    }
}


int main()
{
    c_p_c();
    solve();
    return 0;
}