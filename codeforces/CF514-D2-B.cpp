/*
Mohamed Lahyane (Anir_Ln)
2021-10-19
12:44:24
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

int gcd(int a, int b) {
    if(b==0)
        return a;
    if(a == 1 || b == 1)
        return 1;
    return gcd(b, a%b);
}


string d(int a, int b) {
    if(a==0)
        return "0";
    if( a==b )
        return "1";
    bool neg = false;
    if(a<0 && b<0) {
        a = -a; b = -b;
    }
    else if(a<0 || b<0) {
        neg = true;
        a = abs(a);
        b = abs(b);
    }

    int u = max(a, b);
    int d = a + b - u;
    string ans;
    if(u%d==0) {
        ans = to_string(u/d);
        if(u != a)
            ans = "1/" + ans;
    } else {
        int g = gcd(u, d);
        if(g == 1) 
            ans = to_string(a) + "/" + to_string(b);
        else
            ans = to_string(a/g) + "/" + to_string(b/g);
    }

    if(neg)
        ans = "-" + ans;
    return ans;
}

void solve(){
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    // cout << d(0, -2);
    int x, y;
    map<string,bool> memo; 
    int mx = 0;
    forn(i, n) {
        cin >> x >> y;
        x -= x0;
        y -= y0;
        if(x==0 && y==0) {
            mx = 1;
            continue;
        }
        if(x==0)
        {
            memo["x"]=true;
            continue;
        }
        memo[d(y, x)]=true;
    }

    cout << max(mx, (int)memo.size())  << ln;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}