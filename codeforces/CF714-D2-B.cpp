/*
Mohamed Lahyane (Anir_Ln)
2021-09-25
21:01:37
*/
#include <iostream>
//#include <complex>
#include <queue>
//#include <set>
#include <unordered_set>
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
    int n, tmp;
    unordered_set<int> s;
    cin >> n;
    while(n--){
        cin >> tmp;
        s.insert(tmp);
    }


    if(s.size() > 3){
        cout << "NO" << ln;
        return;
    }

    vector<int> v(s.begin(), s.end());
    sort(all(v));
    string ans = "NO";
    if(v.size() == 2){
        int diff = (v[1] - v[0]);
        int a = v[0] + v[1];
        if(2*v[0] == a - diff && 2*v[1] == a + diff)
        {
            ans = "YES";
        }
    }
    if(v.size() == 3 && v[0] + v[1] + v[2] == 3*v[1]){
        ans = "YES";
    }

    if(v.size() == 1)
        ans = "YES";

    cout << ans << ln;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}