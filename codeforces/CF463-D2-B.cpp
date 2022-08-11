#include <iostream>


using namespace std;

// Brute Force

int main(){
    int n, hi;
    int e = 0;
    int h = 0;
    int m = 0;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> hi;
        if(h >= hi){
            e += h - hi;
        } else {
            int diff = h + e - hi;
            if(diff >= 0){
                e += h - hi;
            } else {
                m -= diff;
                e = 0;
            }
        }
        h = hi;
    }


    cout << m << endl;

    return 0;
}