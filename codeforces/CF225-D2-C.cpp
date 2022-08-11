/*
Mohamed Lahyane (Anir_Ln)
2021-09-29
22:00:15
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
#include <unordered_map>
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

int x, y, n, m;
int arr[10001] = {0};
int preSum[10001] = {0};
unordered_map<string, int> memo;


int sum(int i, int type, int k = 0){
    // arr[i] + arr[i+1] + ... + arr[i+x]
    if(k == 1)
        if(type == 1)
            return n- arr[i];
        else 
            return arr[i];
    int ans;
    if(i == 0)
        ans = preSum[x-1];
    else
        ans = preSum[i+x-1] - preSum[i-1];
    
    if(type == 1)
        return n*x - ans;
    return ans;

}

// act (action)
// act = 1 -> add
// act = -1 -> substract
// int pixel(int col, int width, int act){

//     if(col >= m)
//         return 0;

//     if(width > y)
//         return pixel(col, 0, act);

//     string key = to_string(col) + "_" + to_string(width) + "_" + to_string(act);

//     if(memo.find(key) != memo.end()) 
//         return memo[key];

//     if(width == 0){
//         if(act == 0)
//             return memo[key] = min(sum(col) + pixel(col+x, x, -1), n*x - sum(col) + pixel(col+x, x, 1));

//         if(col+x <= m)
//         {
//             if(act == 1)
//                 return memo[key] = sum(col) + pixel(col+x, x, -1);
//             else
//                 return memo[key] = n*x - sum(col) + pixel(col+x, x, 1);
                
//         }
//         else
//             return (int)1e6;
//     }

//     if(width <= y){
//         if(act == -1)
//             return memo[key] = min(arr[col] + pixel(col+1, width+1, -1), pixel(col, 0, act));
//         else   
//             return memo[key] = min(n - arr[col] + pixel(col+1, width+1, act), pixel(col, 0, act));
//     }


//     return memo[key] = 0;
// }



int ans(int col, int w, int last) {
    if(col >= m)
        return 0;
    
    if(last == 0)
        return min(sum(col, 1) + ans(col+x, x, 1), sum(col, -1) + ans(col+x, x, -1));
    
    string key = to_string(col) + "_" + to_string(w) + "_" + to_string(last);

    if(memo.find(key) != memo.end()) 
        return memo[key];
    

    if(w == 0 || w > y) {
        if(col + x <= m)
            return memo[key] = sum(col, -last) + ans(col+x, w+x, -last);
        else
            return memo[key] = (int)1e6;
    }

    if(w <= y) {
        return memo[key] = min(sum(col, last, 1) + ans(col+1, w+1, last), ans(col, 0, last));
    }

    return memo[key] = 0;
}


void print_r(){
    forn(i, m){
        cout << arr[i] << sp;
    }
    cout << ln;

    forn(i, m){
        cout << preSum[i] << sp;
    }
    cout << ln;
}



void solve(){
    cin >> n >> m >> x >> y;
    char c;
    forn(i, n){
        forn(j, m){
            cin >> c;
            if(c == '#')
                arr[j]++;
        }
    }

    preSum[0] = arr[0];
    forn(i, m-1){
        preSum[i+1] = preSum[i] + arr[i+1];
    }

    // print_r();
    memo.clear();
    cout << ans(0, 0, 0) << ln;

}


int main()
{
    c_p_c();
    solve();
    return 0;
}