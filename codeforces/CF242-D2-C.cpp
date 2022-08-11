/*
Mohamed Lahyane (Anir_Ln)
2021-09-23
15:23:52
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


int bfs(p32 start, p32 end, map<p32, int> &allowed){
    queue<p32> q;
    q.push(start);
    allowed[start] = 0;


    p32 curr, tmp;
    while(!q.empty()){
        curr = q.front();
        q.pop();

        forsn(i, -1, 2){
            forsn(j, -1, 2){
                tmp = {curr.ff + i, curr.ss + j};
                if((i != 0 || j != 0) && allowed.find(tmp) != allowed.end()){

                    // not already visited != -1
                    if(tmp == end){
                        return allowed[curr] + 1;
                    }

                    if(allowed[tmp] == -1){
                        allowed[tmp] = allowed[curr] + 1;
                        q.push(tmp);
                    }                    
                }
            }
        }
    }

    return -1;
}


void solve(){
    p32 start, end;
    map<p32, int> allowed;
    int n, r, a, b;
    cin >> start.ff >> start.ss >> end.ff >> end.ss;
    cin >> n;
    while(n--){
        cin >> r >> a >> b;
        for(int i=a; i<=b; i++){
            allowed[{r, i}] = -1;
        }
    }
    int res = bfs(start, end, allowed);
    cout << res << ln;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}