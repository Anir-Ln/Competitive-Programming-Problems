/*
Mohamed Lahyane (Anir_Ln)
2021-11-10
12:49:05
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

int count_ = 0;







void countSums(int sum, int i, int j, int l, int r, v32& c) {
    cout << i << sp << j << sp;
    if(i>j)
        return;
    cout << "- " << sum << ln; 
    if(sum <= r && sum >= l)
        count_++;
    countSums(sum+c[i], i+1, j, l, r, c);
    countSums(sum, i+1, j, l, r, c);
}



void solve(){
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    
    v32 arr(n);
    forn(i, n)
        cin >> arr[i];
    int ans = 0;
    int mx, mn, sum;
    int nb = pow(2, n)-1;
    
    for(int i=3; i<=nb; i++) {
        sum = 0;
        mx = 0;
        mn = INT_MAX;
        for(int j=0; j<n; j++) {
            if((i>>j)&1){
                // cout << arr[j] << sp;
                sum += arr[j];
                if(sum > r)
                    break;
                mn = min(mn, arr[j]);
                mx = max(mx, arr[j]);
            }
        }
        // cout << ln;
        if(sum >= l && sum <= r && mx - mn >= x) {
            ans++;
        }
    }

    cout << ans << ln;
    // sort(all(c));
    // ll ans = 0;
    // int x_times = 0;

    // for(int i=0; i<n-1; i++) {
    //     for(int j=i+1; j<n; j++) {
    //         if(c[j] - c[i] >= x && c[i] + c[j] <= r) {
    //             // cout << i << sp << j << ln;
    //             count_ = (c[i] + c[j] >= l);
    //             countSums(c[i]+c[j], i+1, j-1, l, r, c);      
    //             ans += count_;
    //         }
    //     }
    // }
}


int main()
{
    c_p_c();
    solve();
    return 0;
}