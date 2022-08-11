/*
Mohamed Lahyane (Anir_Ln)
2021-09-19
18:36:11
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <iostream>
//#include <complex>
//#include <queue>
#include <set>
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



void solve(){

}


int main()
{
    fast_cin();
    //c_p_c();
    int n, m;
    int l = -1;
    int r = 0;
    int u = 0;
    int d = 0;
    char D;

    cin >> n >> m;
    cin >> D;
    char s[n][m];
    forn(i, n){
        forn(j, m){
            cin >> s[i][j];
            // if(l == -1 && s[i][j] == D){
            //     l = j;
            //     u = i;
            // }
        }
    }


    set<char> neig;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i][j] == D){
                for(int k = 0; k<=1; k++){
                    if(i+k >= 0 && i+k < n && j+k-1 >= 0 && j+k-1 < m){
                        if(s[i+k][j+k-1] != D && s[i+k][j+k-1] != '.')
                            neig.insert(s[i+k][j+k-1]);
                    }
                    if(i-k >= 0 && i-k < n && j-k+1 >= 0 && j-k+1 < m){
                        if(s[i-k][j-k+1] != D && s[i-k][j-k+1] != '.')
                            neig.insert(s[i-k][j-k+1]);
                    }
                }
            }
        }
    }

    cout << sz(neig);

    // int j = l;
    // int i = u;
    // while(j<m && s[u][j] == D)
    //     j++;
    // r = j-1;
    // while(i<n && s[i][l] == D)
    //     i++;
    // d = i-1;

    // // find # adjacent deputies
    // int count = 0;
    // if(u > 0){
    //     count += (s[u-1][l] != '.');
    //     j = l+1;
    //     while(j<=r){
    //         if(s[u-1][j] != '.' && s[u-1][j] != s[u-1][j-1]){
    //             count++;
    //         }
           
    //         j++;
    //     }
    // }
    // // cout << "after1_: " << count << ln;
    // if(d+1 < n){
    //     count += (s[d+1][l] != '.');
    //     j = l+1;
    //     while(j<=r){
    //         if(s[d+1][j] != '.' && s[d+1][j] != s[d+1][j-1]){
    //             count++;
    //         }
           
    //         j++;
    //     }
    // }

    // if(l > 0){
    //     count += (s[u][l-1] != '.');
    //     i = u+1;
    //     while(i<=d){
    //         if(s[i][l-1] != '.' && s[i][l-1] != s[i-1][l-1]){
    //             count++;
    //         }
           
    //         i++;
    //     }
    // }

    // if(r+1 < m){
    //     count += (s[u][r+1] != '.');
    //     i = u+1;
    //     while(i<=d){
    //         if(s[i][r+1] != '.' && s[i][r+1] != s[i-1][r+1]){
    //             count++;
    //         }
           
    //         i++;
    //     }
    // }

    // cout << count << ln;
    // cout << l << sp << r << sp << u << sp << d;
    



    return 0;
}
