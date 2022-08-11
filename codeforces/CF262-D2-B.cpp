/*
Mohamed Lahyane (Anir_Ln)
2021-10-09
18:26:42
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



int solve(){
    int n, k;
    cin >> n >> k;
    int arr[n];

    int neg = 0;
    int sump = 0;
    int sumn = 0;
    int zero = 0;
    forn(i, n)
    {
        cin >> arr[i];
        if(arr[i] == 0)
            zero++;
        if(arr[i] < 0){
            sumn += arr[i];
            neg++;
        } else {
            sump += arr[i];
        }
    }

    // if(neg == n){
    //     if(k == n)
    //         return -sumn;
    //     if(k > n)
    //     {
    //         if(k%2)
    //             return -sumn + 2*arr[n-1];
    //         else
    //             return -sumn;
    //     }
    //     int s = 0;
    //     for(int i=0; i<k; i++)
    //         s += -arr[i];
    //     return s + 2*sumn; 
    // }


    if(neg == 0){
        if(k%2 == 0 || zero)
            return sump;    
        return sump - 2*arr[0];
    }

    if(neg == k)
        return -sumn + sump;

    if(k > neg)
    {
        k = k - neg;
        if(k%2 == 0 || zero) 
            return -sumn + sump;
        else {
            if(neg == n || -arr[neg-1] < arr[neg])
                return 2*arr[neg-1] - sumn + sump;

            return -sumn + sump - 2*arr[neg];
        }
    }

    int s = 0;
    for(int i=0; i<k; i++)
        s += -arr[i];
    return 2*s + sumn + sump;


}


int main()
{
    c_p_c();
    cout << solve() << ln;
    return 0;
}