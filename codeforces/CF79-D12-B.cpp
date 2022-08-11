/*
Mohamed Lahyane (Anir_Ln)
2021-09-20
19:15:07
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <iostream>
//#include <complex>
//#include <queue>
//#include <set>
//#include <unordered_set>
//#include <list>
//#include <chrono>
//#include <random>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
// #include <map>
// #include <unordered_map>
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
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
void c_p_c()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void binarySearch(vp32 waste, p32 q){
    int right = sz(waste) - 1;
    int left = 0;

    while(left < right){
        int mid = (left + right)/2;
        if(waste[mid].ff > q.ff){
            right = mid - 1;
        } else if(waste[mid].ff < q.ff){
            left = mid + 1;
        } else {
            
        }
    }
}


bool cmp(p32 a, p32 b){
    if(a.ff == b.ff)
        return a.ss < b.ss;
    return a.ff < b.ff;
}

void print_p32(vector<p32> arr, int n){
    forn(i, n)
        cout << arr[i].ff << sp << arr[i].ss << ln;
}


int linearSearch(vp32& waste, p32 q){
    int l = 0;
    int n = sz(waste);
    // cout << "cmp " << (q < waste[l]) << ln;
    // cout << "q : " << q.ff << sp << q.ss << ln;
    // cout << "waste[i] :  " << waste[l].ff << sp << waste[l].ss << ln;
    while(l < n && q > waste[l]){
        l++;
        // cout << "-";
    }
    if(waste[l] == q)
    {
        return -1;
    }    
    // cout << " l = " << l << ln;
    return l;
}



void solve(){
    string plant[3] = {"Carrots", "Kiwis", "Grapes"};
    int n, m, t, k;
    cin >> n >> m >> k >> t;
    vp32 waste(k);
    // vp32 queries(t);
    
    forn(i, k)
        cin >> waste[i].ff >> waste[i].ss;
    // forn(i, t)
    //     cin >> queries[i].ff >> queries[i].ss;
    sort(all(waste), cmp);


    // int q = 0, w = 0;
    // int num_waste_so_far = 0;
    int num;
    // loop over queries
    p32 q;
    forn(i, t){
        cin >> q.ff >> q.ss;
        // binarySearch(waste, q);
        int w = linearSearch(waste, q);
        if(w == -1){
            cout << "Waste" << ln;
            continue;
        }
        if(q.ff)
            num = (q.ff - 1) * m;
        num += q.ss - w;
        // zero indexing 
        num += 2;
        cout << plant[num%3] << ln;
        // cout << "q : " << q.ff << sp << q.ss << ln;
        // cout << "w : " << w << " - num : " << num << ln;
    }


    // while(q < t && w < k){
    //     if(cmp(waste[w], queries[q])){
    //         // treat case where query is bigger than waste
    //         w++;
    //     } else if(waste[w].ff == queries[q].ff && waste[w].ss == queries[q].ss){
            
    //         q++;
    //         w++;
    //     } else {
    //         //treat(queries[q], w);
    //         num = waste[q].ff * m + waste[1].ss + 1 - w; // num of cultivated cells
    //         cout << plant[num%3] << ln;
    //         q++;
    //     } 
    // }
    

    // using map<int, vector<int>>
    // unordered_map<int, v32> waste;
    // int tmp1, tmp2;
    // forn(i, k){
    //     cin >> tmp1 >> tmp2;
    //     waste[tmp1].pb(tmp2);
    // }
    
    
    // int big;
    // int sml;
    // forn(i, t){
    //     cin >> tmp1 >> tmp2;
    //     int len = waste[tmp1].size();
    //     big = waste[tmp1][0];
    //     sml = big;
    //     for(i, len){
    //         if(waste[])
    //     }
    // }


    // cout << "waste: " << ln;
    // print_p32(waste, k);
}


int main()
{
    fast_cin();
    // c_p_c();
    solve();
    // vp32 v = {{1, 1}, {1, 2}, {3, 4}};
    // v.pb({1, 3});
    // cout << linearSearch(v, make_pair(1, 3));
    return 0;
}