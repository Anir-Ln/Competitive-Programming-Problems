/*
Mohamed Lahyane (Anir_Ln)
2021-11-05
23:06:29
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



void solve(){
    string s, t;
    cin >> s >> t;
    int ns = s.size(), nt = t.size();

    int alpha[26] = {0};
    for(char c : s) {
        alpha[c - 'a']++;
    } 
    for(char c : t) {
        alpha[c - 'a']--;
    }

    int count = 0;
    int pos = 0, neg = 0;

    for(int i=0; i<26; i++) {
        count += abs(alpha[i]);
        if(alpha[i] < 0)
            neg += -alpha[i];
        else 
            pos += alpha[i];
    }

    // count == 0 -> all chars in s are in t and ns == nt
    if(!count) {
        cout << "array" << ln;
        return;
    }


    // neg != 0 -> there are chars in t that r not in s
    if(neg) {
        cout << "need tree" << ln;
        return;
    } 
    
    int i=0, j=0;
    // se if there is a seqence in s that is equal to t
    while(i<ns && j<nt) {
        if(s[i] == t[j])
        {
            i++;
            j++;
        } else {
            i++;
        }
    }
    // yes there is
    if(j == nt) {
        // yees
        cout << "automaton" << ln;
        return;
    }

    // else there are char in s that are not in t which should be removed, but all letters in t are in s, but not in the same order -> should remove and swap
    cout << "both" << ln;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}