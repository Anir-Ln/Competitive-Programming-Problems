/*
Mohamed Lahyane (Anir_Ln)
2021-09-24
19:57:56
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

ll combination[15][15];

ll C(int n, int k){
    if(k == 0 || k == n)
        return 1;

    if(combination[n][k] != -1)
        return combination[n][k];
    
    combination[n][k] = C(n-1, k-1) + C(n-1, k);
    return combination[n][k];
}


double solve(){
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = sz(s1);
    int len2 = sz(s2);

    int p1, p2, n1, n2, un;
    p1 = p2 = n1 = n2 = un = 0;
    double ans = 0.;
    forn(i, len1){
        if(s1[i] == '+')
            p1++;
        else 
            n1++;
    }
    forn(i, len2){
        if(s2[i] == '+')
            p2++;
        else if(s2[i] == '-')
            n2++;
        else 
            un++;
    }

    if(p2 > p1 || n2 > n1)
        return ans;
    if(un == 0){
        if(p1 == p2 && n1 == n2){
            ans = 1;     
        } else {
            ans = 0;
        }
        return ans;
    } 

    int p_diff, n_diff;
    p_diff = p1 - p2;
    n_diff = n1 - n2;
    // find all possible combinations to have the needed # of + and -
    ll comb = C(un, min(n_diff, p_diff));
    // divide by total # of possibilities
    return (double) comb/pow(2, un); 
}


void initialize(){
    forn(i, 15){
        forn(j, 15)
            combination[i][j] = -1;
    }
}

int main()
{
    c_p_c();
    initialize();
    cout << fixed << setprecision(12) << solve();
    return 0;
}