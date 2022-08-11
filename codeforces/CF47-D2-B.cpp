#include <iostream>


using namespace std;

void modify(string &s){
    if(s[1] == '>')
        return;
    
    swap(s[0], s[2]);
}


/*
idea:
modify the input to be:
letter > letter
letter > letter
letter > letter

if every letter shows only once in the left (or right side) => impossible because every coin cannot be greater than every other coin
the normal case is when a coin is greater than 2 other coins and one greater than 1 coin and last one is less thna both of the 2 first coins;
e.g => 210
*/

void solve(){
    // string letters = " ABC";
    string s;
    int count[3] = {0};
    for(int i=0; i<3; i++){
        cin >> s;
        modify(s);
        count[s[0] - 'A']++;
    }
    int mx = 0;
    int index;
    for(int i=0; i<3; i++){
        if(mx < count[i]){
            mx = count[i];
            index = i;
        }
    }

    if(mx != 2){
        cout << "Impossible" << endl;
        return;
    }

    for(int j=0; j<=2; j++){
        for(int i=0; i<3; i++){
            if(count[i] == j){
                cout << (char)('A'+i);
                continue;
            }
        }
    }

    cout << endl;
}




int main(){
    solve();

    return 0;
}
