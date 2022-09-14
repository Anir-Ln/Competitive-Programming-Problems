
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

int num_moves(p32 start, p32 end) {
//	cout << start.ff << sp << start.ss << sp << end.ff << sp << end.ss << ln;
	pair<p32, int> curr = {start, 0};
	queue<pair<p32, int>> q;
	q.push(curr);

	map<p32, bool> visited;
		
	p32 nextPoint;
	p32 currPoint;
	visited[start] = true;
	while(!q.empty()) {
		curr = q.front(); q.pop();
//		cout << curr.ff.ff << sp << curr.ff.ss << sp << curr.ss << ln;
		currPoint = curr.ff;

		for (int i=-2; i<3; i++) {
			for (int j=-2; j<3; j++) {
				if (i == 0 || j == 0 || abs(i) == abs(j)) continue;
				nextPoint = {currPoint.ff + i, currPoint.ss + j};
				if (nextPoint.ff < 0 || nextPoint.ff > 7 || nextPoint.ss < 0 || nextPoint.ss > 7) 
					continue;
				if (visited[nextPoint]) continue;					
				visited[nextPoint] = true;
				if (nextPoint.ff == end.ff && nextPoint.ss == end.ss) return curr.ss + 1; 
				q.push(mp(nextPoint, curr.ss + 1));	
			}
		}
	}
	return -1;
}

void solve(){
  	string start, end;
		int res;
		while(cin >> start >> end) {
			if (start == end)
				res = 0;
			else 
				res = num_moves({(start[1] - '1'), start[0] - 'a'}, {(end[1] - '1'), end[0] - 'a'});
			cout << "To get from " << start <<  " to " << end << " takes " << res << " knight moves." << ln;
		}
}


int main()
{
	c_p_c();
	solve();
	return 0;
}

