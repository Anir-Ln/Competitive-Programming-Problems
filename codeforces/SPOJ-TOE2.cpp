/*
Mohamed Lahyane (Anir_Ln)
2021-09-22
15:23:55
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



bool is_win(string conf){
    for(int i=0; i<9; i+=3){
        if(conf[i] == '.')
            continue;
        if(conf[i] == conf[i+1] && conf[i+1] == conf[i+2])
            return true;
    }
    for(int i=0; i<3; i++){
        if(conf[i] == '.')
            continue;
        if(conf[i] == conf[i+3] && conf[i+3] == conf[i+6])
            return true;
    }
    if(conf[4] == '.')
        return false;
    return (conf[0] == conf[4] && conf[4] == conf[8]) || (conf[2] == conf[4] && conf[4] == conf[6]);

}

bool bfs(string wanted){
    string conf = ".........";
    map<string, bool> visited;
    queue<pair<string, bool> > q;
    q.push(mp(conf, true));
    pair<string, bool> curr;
    string tmp;
    while(!q.empty()){
        curr = q.front();
        // cout << curr.ff << endl;
        q.pop();
        // also making sure that the start config is not the wanted one
        // if "........." == wanted that's false, because the start config is never the end config
        if(curr.ff == wanted)
            return false;
        // we construct all the possible config from the current one
        forn(i, 9){
            if(curr.ff[i] == '.'){
                tmp = curr.ff;
                tmp[i] = (curr.ss ? '1' : '0');
                // if the conf has already been visited, we pass it
                if(visited[tmp])
                    continue;
                bool win = is_win(tmp);
                if(tmp == wanted)
                {
                    if(win){
                        return true;
                    } else {
                        forn(i, 9){
                            if(tmp[i] == '.')
                                return false;
                        }
                        return true;
                    }
                }
                visited[tmp] = true;
                if(win){
                    continue;
                }
                // to make sure the constructed config is on the way to the wanted one
                if(tmp[i] == wanted[i])
                    q.push(mp(tmp, !curr.ss));
            }
        }
    }

    return false;
}



void solve(string s){
    // int count = 0;
    forn(i, 9)
    {
        if(s[i] == 'X'){
            s[i] = '1';
            // count++;
        } else if(s[i] == 'O'){
            s[i] = '0';
            // count++;
        }
    }
    // cout << "s: " << s << endl;
    bool res = bfs(s);
    cout << (res ? "valid" : "invalid") << ln;
}


int main()
{

    c_p_c();
    
    // cout << (is_win(s) ? "YES" : "NO") << endl;
    // cout << "wanted = " << s << ln;
    string s;
    while(true){
        cin >> s;
        if(s == "end")
            break;
        solve(s);
    }
    return 0;
}
