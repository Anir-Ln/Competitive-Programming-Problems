/*
Mohamed Lahyane (Anir_Ln)
2021-09-18
21:41:12
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

// check if a and b are relatively prime
// int is_re_prime(int a, int b){
//     if(!(a&1) && !(b&1))
//         return 0;
//     int mn = min(a, b);
//     if(a%mn == 0 && b%mn == 0)
//         return 0;
//     for(int i=3; i*i <= mn; i+=2){
//         if(a%i == 0 && b%i == 0)
//             return 0;
//     }
//     // cout << '(' << a << ", " << b << ')' << ln;
//     return 1;
// }

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

void solve(int n){
    int arr[n];
    forn(i, n){
        cin >> arr[i];
    }
    int count = 0;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            // count += is_re_prime(arr[i], arr[j]);
            if(gcd(max(arr[i], arr[j]), min(arr[i], arr[j])) == 1)
                count++;
        }
    }

    if(count == 0)
    {
        cout << "No estimate for this data set." << ln;
        return;
    }
    // cout << "count = " << count << "\t";
    ld pairs = (ld) n*(n-1)/2;
    ld res = (ld)6.000000*pairs/count;
    cout << fixed << setprecision(6) << sqrtl(res) << endl;
}


int main()
{
    fast_cin();
    c_p_c();
    int n;
    while(true){
        cin >> n;
        if(!n)
            break;
        solve(n);
    }
    return 0;
}
