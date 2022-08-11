/*
Mohamed Lahyane (Anir_Ln)
2021-09-20
17:21:07
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
#define sp ' '
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
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


// maximize the sell-out products means take the double the first f days where min(2a, b) is greater
bool cmp(int *a, int *b){
    if(a[0] > a[1])
        return false;
    
    if(b[0] > b[1])
        return true;

    return (min(a[0], a[1] - a[0]) > min(b[0], b[1] - b[0]));
}


void print_arr(int *arr[], int n){
    forn(i, n)
        cout << arr[i][0] << sp << arr[i][1] << ln;
}

void solve(){
    int n, f;
    cin >> n >> f;
    int **arr = new int*[n];
    ll sum = 0;
    forn(i, n)
        *(arr + i) = new int[2];
    
    forn(i, n){
        cin >> arr[i][0] >> arr[i][1];
        sum +=  (ll)min(arr[i][0], arr[i][1]);
    }
    sort(arr, arr + n, cmp);
    forn(i, f){
        if(arr[i][0] > arr[i][1])
            break;
        sum += (ll) min(arr[i][0], arr[i][1] - arr[i][0]);
    }

    // print_arr(arr, n);
    cout << sum << ln;
    
    forn(i, n)
        delete[] arr[i];
    delete[] arr;
    
}


int main()
{
    fast_cin();
    //c_p_c();
    solve();
    return 0;
}