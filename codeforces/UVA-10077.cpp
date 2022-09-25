
/*
Mohamed Lahyane (Anir_Ln)
*/

#include <iostream>
//#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
//#include <list>
//#include <chrono>
//#include <random>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <limits>

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

#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
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
/*
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
*/
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}



void solve(){
	int m, n;
	p32 left, right, mid;
	while(cin >> m >> n) {
		if (m == 1 && n == 1) break;
		string res = "";
		left = {0, 1}, right = {1, 0}, mid = {1, 1};
		while(mid.first != m || mid.second != n) {
			// to know which direction to chose, we should compare the current mid, with the desired destination
			// to the left if the m/n is smaller then mid otherwise right
			int v = m * mid.ss - n * mid.ff;
			if (v < 0) {
				// go left
				right = mid;
				mid = {mid.ff + left.ff, mid.ss + left.ss};
				res += 'L';
			} else {
				// go right
				left = mid;
				mid = {mid.ff + right.ff, mid.ss + right.ss};
				res += 'R';
			}
		}
		cout << res << ln;
	}
}


int main()
{
	c_p_c();
	cout << fixed << setprecision(12);
	solve();
	return 0;
}

