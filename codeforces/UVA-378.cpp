/*
Mohamed Lahyane (Anir_Ln)
2021-10-20
13:44:23
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



// void solve(){
//     double x1, x2, x3, x4, y1, y2, y3, y4;
//     cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
//     double d1=(x2-x1)*(y2-y3)-(y2-y1)*(x2-x3), d2=(x2-x1)*(y2-y4)-(y2-y1)*(x2-x4);
  
//     cout << fixed <<setprecision(2);  

//     if(!d1 && !d2) {
//         cout << "LINE" << ln;
//         return;
//     }
//     if(!d1) {
//         cout << "POINT " << x1 << sp << y1 << ln;
//         return;
//     }
//     if(!d2) {   
//         cout << "POINT " << x2 << sp << y2 << ln;
//         return;
//     }
    
//     if((x2-x1)*(y4-y3)-(y2-y1)*(x4-x3) == 0)
//     {
//         cout << "NONE" << ln;
//         return;
//     }
//     double a0, a1, b0, b1;
//     if(x1 == x2)
//     {
//         a1 = (y3-y4)/(x3-x4);
//         b1 = y3 - a1*x3;
//         cout << "POINT" << sp << x1 << sp << a1*x1+b1 << ln;
//         return;
//     }
//     if(x3 == x4) {
//         a0 = (y1-y2)/(x1-x2);
//         b0 = y1 - a0*x1;
//         cout << "POINT" << sp << x3 << sp << a0*x3+b0 << ln;
//         return;
//     }
//     a0 = (y1-y2)/(x1-x2);
//     a1 = (y3-y4)/(x3-x4);
//     b0 = y1 - a0*x1;
//     b1 = y3 - a1*x3;
//     if(a0 == a1)
//     {
//         cout << "NONE" << ln;
//         return;
//     }
//     double x = (b1-b0)/(a0-a1);
//     double y = a0*x + b0;
//     cout << "POINT" << sp;
//     cout << x << sp << y << ln;
// }




void solve(){
    double x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4; 
    cout << fixed <<setprecision(2);  

    double cross = (x2-x1)*(y4-y3) - (x4-x3)*(y2-y1);
    if(cross == 0){
        if((y2-y1)*(x3-x1) - (x2-x1)*(y3-y1) == 0) {
            cout << "LINE" << ln;
            return; 
        }
        cout << "NONE" << ln;
        return;
    }
    double a1, b1, a2, b2;
    if(x2 == x1 || x3 == x4) {
        if(x3 == x4) {
            swap(x3, x1);
            swap(y1, y3);
            swap(y2, y4);
            swap(x2, x4);
        }
        a2 = (y4-y3)/(x4-x3);
        b2 = y3 - a2*x3;
        cout << "POINT" << sp;
        cout << x1 << sp << a2*x1 + b2 << ln;
        return;
    }
    a1 = (y2-y1)/(x2-x1);
    b1 = y1 - a1*x1;
    a2 = (y4-y3)/(x4-x3);
    b2 = y3 - a2*x3;
    double x = (b1-b2)/(a2-a1);
    cout << "POINT" << sp << x << sp << a1*x+b1 << ln;
}


int main()
{
    c_p_c();
    ll t;
    cin >> t;
    cout << "INTERSECTING LINES OUTPUT" << ln;
    for(int it=0; it<t; it++) {
        // cout << "Case #" << it+1 << ": ";
        solve();
    }
    cout << "END OF OUTPUT" << ln;
    return 0;
}