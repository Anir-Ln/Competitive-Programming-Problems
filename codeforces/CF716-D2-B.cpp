/*
Mohamed Lahyane (Anir_Ln)
2021-11-06
20:57:14
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
    string s;
    cin >> s;

    int n = s.size();
    // cout << "len: " << n << ln;
    if(n < 26) 
    {
        cout << -1 << ln;
        return;
    }

    int alpha[26] = {0};
    int count = 0;

    for(int i=0; i<26; i++) {
        if(s[i] == '?') {
            count++;
        } else {
            alpha[s[i] - 'A']++;
        }
    }
    int let = 0;
    for(int i=0; i<26; i++) {
        let += (alpha[i] != 0);
    }

    if(let + count == 26){
        string w = "";
        for(int i=0; i<26; i++) {
            if(alpha[i] == 0) 
                w.push_back((char)('A' + i));
        }
        int index = 0;
        for(int j=0; j<26; j++) {
            if(s[j] == '?')
                s[j] = w[index++];
        }
        for(char& c: s) {
                if(c == '?') {
                    c = 'A';
                }
            }
        cout << s << ln;
        return;
    }

    int i = 26;

    while(i<n) {

        if(s[i-26] == '?') {
            count--;
        } else {
            alpha[s[i-26]-'A']--;
            if(alpha[s[i-26]-'A'] == 0) 
                let--;
        }

        if(s[i] == '?') {
            count++;
        } else {
            if(alpha[s[i]-'A'] == 0) 
                let++;
            alpha[s[i]-'A']++;
        }
        // cout << let << sp << count << ln;
        if(let + count == 26) {
            string w = "";
            for(int x=0; x<26; x++) {
                if(alpha[x] == 0) 
                    w.push_back((char)('A' + x));
            }
            int index = 0;
            for(int j = i; j>i-26; j--) {
                if(s[j] == '?')
                    s[j] = w[index++];
            }
            for(char& c: s) {
                if(c == '?') {
                    c = 'A';
                }
            }
            // cout << "i = " << i << ln; 
            cout << s << ln;
            return;
        }
        i++;
    }
    
    cout << -1;
}


int main()
{
    c_p_c();
    solve();
    return 0;
}