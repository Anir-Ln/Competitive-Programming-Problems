
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

int get_time_i(int i, vv32 &graph, v32 &time, vector<bool> &visited) {
	if (visited[i]) return 0;
	visited[i] = true;
	int ret = time[i];
	for (int dep: graph[i]) ret += get_time_i(dep, graph, time, visited);
	return ret;
}

v32 get_time(int v, vv32 &graph, v32 &time) {
	v32 res(v);
	vector<bool> visited(v);
	forn(i, v) {
		fill(visited.begin(), visited.end(), false);
		res[i] = get_time_i(i, graph, time, visited);
	}
	return res;
}


void solve(int v, int e){
	v32 time(v);
	int sum_time = 0;
	forn(i, v) { cin >> time[i]; sum_time += time[i]; }

	vv32 in_graph(v, v32());
	vv32 out_graph(v, v32());
	int a, b;
	forn(i, e) {
		cin >> a >> b; a--; b--;
		in_graph[a].push_back(b);
		out_graph[b].push_back(a);
	}
	
	v32 out_time = get_time(v, in_graph, time);
	v32 in_time = get_time(v, out_graph, time);

	int q, x;
	cin >> q;
	while(q--) {
		cin >> x;
		x--;
		cout << sum_time - in_time[x] - out_time[x] + time[x] << ln;
	}
}


int main()
{
	c_p_c();
	int v, e;
	int i = 1;
	while(cin >> v >> e) {
		if (v == 0 && e == 0) break;
		cout << "Case #" << i << ":" << ln; 
		solve(v, e);
		cout << ln;
		i++;
	}
	return 0;
}

