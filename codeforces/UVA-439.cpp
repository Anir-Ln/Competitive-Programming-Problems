/*
Mohamed Lahyane (Anir_Ln)
2021-09-22
19:45:48
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


bool valid_pos(p32 pos){
    if(pos.ff < 8 && pos.ff >= 0 && pos.ss < 8 && pos.ss >= 0)
        return true;
    return false;
}


int bfs(p32 start, p32 end){
    queue<p32> q;
    vector<vector<bool> > visited(8, vector<bool>(8));
    vv32 dist(8, v32(8, -1));
    // visited[start.ff][start.ss] = true;
    dist[start.ff][start.ss] = 0;
    q.push(start);
    if(start == end){
        return 0;
    }

    p32 curr;
    p32 tmp;
    while(!q.empty()){
        curr = q.front();
        q.pop();
        // try reachable position from curr
        forn(i, 2){
            forn(j, 2){
                forsn(k, 1, 3){
                    //$+-1, #+-2
                    //$+-2, #+-1
                    tmp = curr;
                    tmp.ff = tmp.ff + k*(i ? 1 : -1);
                    tmp.ss = tmp.ss + (3-k)*(j ? 1 : -1);
                    if(valid_pos(tmp)){
                        // cout << "pos : " << tmp.ff << ", " << tmp.ss << ln;
                        if(dist[tmp.ff][tmp.ss] == -1){
                            dist[tmp.ff][tmp.ss] = dist[curr.ff][curr.ss] + 1;
                            if(tmp == end){
                                return dist[end.ff][end.ss];
                            }
                            q.push(tmp);
                        } else {
                            // already visited
                            // not necessary
                            // dist[tmp.ff][tmp.ss] = min(dist[tmp.ff][tmp.ss], dist[curr.ff][curr.ss] + 1);
                            continue;                        
                        }
                    }
                }
            }
        } 
    }
    return -1;
}



void solve(){
    string s1;
    string s2;
    p32 start, end;
    while((cin >> s1)){
        cin >> s2;
        start = {(int)(s1[0] - 'a'), (int)(s1[1] - '1')};
        end = {(int)(s2[0] - 'a'), (int)(s2[1] - '1')};
        int dist = bfs(start, end);
        // cout << start.ff << sp << start.ss;
        cout << "To get from " << s1 << " to " << s2 << " takes " << dist << " knight moves." << ln;
    }
    
}


int main()
{
    c_p_c();
    solve();
    return 0;
}