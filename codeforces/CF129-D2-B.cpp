/*
Mohamed Lahyane (Anir_Ln)
2021-09-24
16:33:52
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



void solve(){
    int v, e;
    cin >> v >> e;
    vv32 adj(v + 1);

    int a, b;
    forn(i, e){
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int count = 0;
    bool exist;
    v32 leaves;

    while(true){
        leaves.clear();
        exist = false;

        // push all leaves to the leaves vector
        for(int node = 1; node < v+1; node++){
            if(adj[node].size() == 1){
                leaves.pb(node);
                exist = true;
            }
        }
        // delete all leaves from the adjacency list
        for(auto node: leaves){
            int k = 0;
            int parent = adj[node][0];
            if(adj[parent].size() == 0)
                continue;
            while(adj[parent][k] != node){
                k++;
            }
            adj[parent].erase(adj[parent].begin() + k);
            adj[node].erase(adj[node].begin());
        }
        // if we found some leaf we increment count, otherwise the algorithm finishes
        if(exist)
            count++;
        else
            break;
    }



    // int leaf = 4;
    // int parent = adj[leaf][0];
    // int k = 0;
    // while(adj[parent][k] != leaf)
    //     k++;
    // adj[parent].erase(adj[parent].begin() + k);
    // adj[leaf].erase(adj[leaf].begin());

    // for(int i=1; i<v+1; i++){
    //     cout << i << " : ";
    //     for(auto node : adj[i]){
    //         cout << node << sp;
    //     }
    //     cout << ln;
    // }


    cout << count << ln;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}