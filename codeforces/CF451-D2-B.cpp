/*
Mohamed Lahyane (Anir_Ln)
2021-09-20
12:38:58
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



void solve(){
    int n;
    cin >> n;
    int arr[n];
    int left = -1, right;
    int count = 0;
    // int curr_mx = arr[0];
    bool found = false;
    forn(i,n){
        cin >> arr[i];
        
        if(i>0){
            if(arr[i] < arr[i-1]){
                if(!found) {
                    found = true;
                    left = i - 1;
                    count++;
                    if(count > 1){
                        cout << "no" << endl;
                        return;
                    }
                }
                right = i;
            } else {
                found = false;
                // curr_mx = max(curr_mx, arr[i]);
            }
        }
    }

    if(left == -1)
    {
        cout << "yes" << ln;
        cout << 1 << sp << 1 << ln;
        return;
    }


    bool yes = true;
    if(0 != left && arr[right] < arr[left - 1]){
        yes = false;
    }
    if(n-1 != right && arr[left] > arr[right + 1]){
        yes = false;
    }

    if(!yes)
    {
        cout << "no" << ln;
        return;
    }

    cout << "yes" << ln;
    cout << left+1 << sp << right+1 << ln;


}


int main()
{
    fast_cin();
    //c_p_c();
    solve();
    return 0;
}