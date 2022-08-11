/*
Mohamed Lahyane (Anir_Ln)
2021-09-30
19:56:45
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
#include <climits>
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

map<p32, vp32> land;
vector<vector<bool> > visited(21, vector<bool> (21, false));
int x, y;

int dfs(p32 root){
    int res = 1;
    if(root.ff == x && root.ss == y)
        res += INT_MIN;

    if(visited[root.ff][root.ss])
        return 0;
    
    visited[root.ff][root.ss] = true;
    cout << "{" << root.ff << ", " << root.ss << "}" << ln;
    for(auto node: land[root]){
        res += dfs(node);
    }

    return res;
}


void solve(int n, int m){
    forn(i, 21){
        forn(j, m)
            visited[i][j] = false;
    }
    land.clear();
    int arr[n][m];
    vector<string> s(n);
    forn(i, n){
        cin >> s[i];
    }
    cin >> x >> y;
    char f = s[x][y];
    forn(i, n){
        forn(j, m){
            arr[i][j] = (s[i][j] == f);
        }
    }

    
    forn(i, n){
        forn(j, m){
            if(arr[i][j]){
                land[{i, j}].pb({i, j});
                if((i-1) >= 0 && arr[i-1][j]){
                    land[{i, j}].pb({i-1, j});
                }
                if((j-1+m)%m != j && arr[i][(j-1+m)%m]){
                    land[{i, j}].pb({i, (j-1+m)%m});
                }
                if((i+1) <= n-1 && arr[i+1][j]){
                    land[{i, j}].pb({i+1, j});
                }
                if((j+1)%m != j && arr[i][(j+1)%m]){
                    land[{i, j}].pb({i, (j+1)%m});
                }
            }
        }
    }

    // for(auto adj: land){
    //     cout << adj.ff.ff << ", " << adj.ff.ss << ": " << ln;
    //     for(auto node: adj.ss){
    //         cout << node.ff << ", " << node.ss << sp;
    //     }
    //     cout << ln;
    // }

    int mx = 0;
    // fill(all(visited), vector<bool> (21, false));
    
    for(auto node = land.begin(); node != land.end(); node++){
        if(!visited[node->ff.ff][node->ff.ss]){
            mx = max(mx, dfs(node->ff));
        }
        cout << '-' << ln;
    }
    // mx = dfs({3,1});
    cout << mx << ln;
}

// void solve(){
//     int n, m;
//     cin >> n >> m;
//     int arr[n][m];
//     vv32 v(n*m/2);
//     int index = 0;
//     char c;
//     int mx = 0;
//     forn(i, n){
//         forn(j, m){
//             cin >> c;
//             if(c == 'l'){
//                 if(i == 0 && j == 0) {
//                     arr[i][j] = 1; 
//                     continue;
//                 }
//                 if(i == 0)
//                     arr[i][j] = arr[i][j-1] + 1;
//                 else if(j == 0) {
//                     arr[i][j] = arr[i-1][j] + 1;
//                 } else {
//                     arr[i][j] = arr[i][j-1] + arr[i-1][j] + 1;
//                 }
//                 mx = max(arr[i][j], mx);
//             } else {
//                 arr[i][j] = 0;
//             }
//         }
//     }

//     cout << mx << ln;

// }


int main()
{
    c_p_c();
    int n, m;
    while(cin >> n >> m){
        solve(n, m);
    }
    return 0;
}