/*
Mohamed Lahyane (Anir_Ln)
2021-09-21
13:55:14
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
typedef vector<vector<p32> > vvp32;
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
    int n, m, x, q;
    cin >> n >> m >> x;
    vvp32 alpha(26);
    vp32 shift; 
    // string s;
    char k;
    forn(i, n){
        forn(j, m){
            cin >> k;
            if(k == 'S')
                shift.pb({i, j});
            else 
                alpha[k - 'a'].pb({i, j});
        }
    }
    
    map<char, int> s;
    cin >> q;
    forn(i, q){
        cin >> k;
        s[k]++;
    }

    int count = 0;
    p32 let;
    int S = shift.size();
    for(auto item : s){
        if(item.first <= 'z' && item.first >= 'a'){
            if(alpha[item.first - 'a'].empty()){
                cout << -1 << ln;
                return;
            } 
        } else {
            if(alpha[item.first - 'A'].empty() || S == 0){
                cout << -1 << ln;
                return;
            }

            bool found = false;
            bool br = false;
            for(auto let : alpha[item.first - 'A']){
                for(auto sh: shift){
                    if((sh.ff - let.ff)*(sh.ff - let.ff) + (sh.ss - let.ss)*(sh.ss - let.ss) <= x*x){
                        found = true;
                        br = true;
                        break;
                    }
                }
                if(br)
                    break;
            }
            if(!found)
                count += item.ss;
        }
    }


    // cin >> s;

    // forn(i, q){
    //     if(s[i] <= 'z' && s[i] >= 'a'){
    //         if(alpha[s[i] - 'a'].empty()){
    //             cout << -1 << ln;
    //             return;
    //         } 
    //     } else {
    //         if(alpha[s[i] - 'A'].empty() || S == 0){
    //             cout << -1 << ln;
    //             return;
    //         }

    //         bool found = false;
    //         bool br = false;
    //         for(auto let : alpha[s[i] - 'A']){
    //             for(auto sh: shift){
    //                 if(sqrt((float)(sh.ff - let.ff)*(sh.ff - let.ff) + (float)(sh.ss - let.ss)*(sh.ss - let.ss)) <= (float)x){
    //                     found = true;
    //                     br = true;
    //                     break;
    //                 }
    //             }
    //             if(br)
    //                 break;
    //         }
    //         if(!found)
    //             count++;
    //     }
    // }


    cout << count << ln;

}


int main()
{
    fast_cin();
    //c_p_c();
    solve();
    return 0;
}