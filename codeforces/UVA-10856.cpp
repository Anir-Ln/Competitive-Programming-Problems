/*
Mohamed Lahyane (Anir_Ln)
2021-10-09
12:42:32
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
int memo[10000002] = {0};

int ans(int i, int last){
    if(memo[i])
        return memo[i];

    while(i != 1){
        if(i % last == 0){
            return memo[i] = 1 + ans(i/last, last);
        }
        last++;
    }

    return memo[i] = 0;
}


int count(int i){
    int o = i;
    int k = 2;
    int c = 0; 
    while(i != 1){
        if(i%k == 0)
        {
            c++;
            i /= k;
            if(memo[i]){
                c += memo[i];
                break;
            }
            k--;
        }
        k++;
    }
    return memo[o] = c;
}

void solve(int n){
    if(n <= 1)
    {
        cout << 0 << '!' << ln;
        return;
    }

    int prev = 0; // i = 1
    int curr = 1; // i = 2

    int i = 3;
    int tmp;
    while(curr < n){
        // cout << curr << sp;
        prev = curr;
        curr += ans(i, 2);
        i++;
    }

    if(curr == n)
        cout << i-1 << '!' << ln;
    else
        cout << "Not possible" << ln;
}


int main()
{
    c_p_c();
    int n;
    int t = 1;
    while(true){
        cin >> n;
        if(n < 0)
            break;
        cout << "case " << t++ << ":" << sp;
        solve(n);
    }
    
    return 0;
}