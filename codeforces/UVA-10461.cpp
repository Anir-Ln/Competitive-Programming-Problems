/*
Mohamed Lahyane (Anir_Ln)
2021-09-23
17:56:14
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

void bfs(int job){
    v32 notIncluded;
    // find all 
}

int maxTime(int job, int v, v32 &time, vv32 &revDepend, int timeSum){
    int notIncludedSum = time[job];
    vector<bool> visited(v + 1);
    queue<int> q;
    q.push(job);
    visited[job] = true;

    int curr;
    while(!q.empty()){
        curr = q.front();
        q.pop();

        for(int adj: revDepend[curr]){
            if(!visited[adj]){
                visited[adj] = true;
                notIncludedSum += time[adj];
                q.push(adj);
            }
        }
    }

    return timeSum - notIncludedSum;
}

// dfs
int minTime(int job, v32 &time, vv32 &depend, vector<bool> &visited){

    int timeSum = 0;
    for(int adj : depend[job]){
        if(!visited[adj]){
            visited[adj] = true;
            timeSum += time[adj] + minTime(adj, time, depend, visited);
        }
    }

    return timeSum;
}


void solve(int v, int e){
    // nodes, dependancies
  
    vv32 depend(v+1);
    vv32 revDepend(v+1);
    v32 time(v+1);
    // 1-based-indexing
    int timeSum = 0;
    forn(i, v){
        cin >> time[i+1];
        timeSum += time[i+1];
    }
    int a, b;
    forn(i,e){
        cin >> a >> b;
        // 1-indexing
        depend[a].pb(b);
        revDepend[b].pb(a);
    }

    int q;
    cin >> q;
    vector<bool> visited(v+1);
    while(q--){
        fill(all(visited), false);
        cin >> a;
        cout << maxTime(a, v, time, revDepend, timeSum) - minTime(a, time, depend, visited) << ln;
    }



    // cout << maxTime(a, v, time, revDepend, timeSum);
    // cin >> a;
    // cout << minTime(a, time, depend, visited);
}


int main()
{
    c_p_c();
    int v, e;
    int it = 1;
    while(true){
        cin >> v >> e;
        if(v == 0 && e == 0)
            break;  
        cout << "Case #" << it << ":" << ln;
        solve(v, e);
        cout << ln;
        it++;
    }

    return 0;
}