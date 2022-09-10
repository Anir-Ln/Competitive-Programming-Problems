
/*
Mohamed Lahyane (Anir_Ln)
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
//#include <limits>

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

string add(string a, string b) {
	int i=sz(a)-1;
	int j=sz(b)-1;
	string res = "";
	int rest = 0;
	bool ok = false;

	while(i>=0 || j>=0) {
		if (i>=0) rest += (a[i--]-'0');
		if (j>=0) rest += (b[j--]-'0');
		if (ok || rest % 10 != 0) {
			res.pb(rest%10 + '0');
			ok = true;
		}
		rest = rest>=10?1:0;
	}
	if (rest) res.pb('1');
	return res; 
}

string rev(string s) {
	int i=0;
	int n=sz(s);
	while(i<sz(s) && s[n-1-i] == '0') i++;
	if (i>n-1) return "0";
	reverse(s.begin(), s.end()-i);
	return s.substr(0, n-i);
}

void solve() {
	int n;
	cin >> n;
	string a, b;

	while(n--) {
		cin >> a >> b;
		cout << add(rev(a), rev(b)) << ln;
	}
}


int main()
{
	c_p_c();
	cout << fixed << setprecision(9);
	solve();
	return 0;
}

