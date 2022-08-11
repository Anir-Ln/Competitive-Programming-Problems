/*
Mohamed Lahyane (Anir_Ln)
2021-09-29
13:32:49
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

// last = 0 -> rest
// last = 1 -> gym
// last = 2 -> contest
int arr[101];
int memo[101][4];
int n;
int countRest(int d, int last){
    if(d == n)    
        return 0;
    int &res = memo[d][last];
    if(res != -1)
        return memo[d][last];

    // if(arr[d] == 0)
    //     return res = 1 + countRest(d+1, 0);
    if(arr[d] == 1 && last != 2)
        return res = countRest(d+1, 2);
    if(arr[d] == 2 && last != 1)
        return res = countRest(d+1, 1);
    
    if(arr[d] == 3){
        if(last == 0)
            return res = min(countRest(d+1, 1), countRest(d+1, 2));
        else if(last == 1)
            return res = countRest(d+1, 2);
        else 
            return res = countRest(d+1, 1);  
    }

    return res = 1 + countRest(d+1, 0);
}



void solve(){
    cin >> n;
    forn(i, n)
        cin >> arr[i];
    forn(i, 101)
        forn(j, 4)
            memo[i][j] = -1;
        
    cout << countRest(0, 0) << ln;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}