#include <iostream>


using namespace std;


// <implementation> recursive approch (easy)

// sum up all values of the string and add 1 to the output, the same thing recursively on string(sum); 
int solve(string s){
    int n = s.size();
    if(n == 1){
        return 0;
    }
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += (long long)(s[i] - '0');
    }
    // cout << "sum " << sum << endl;
    return 1 + solve(to_string(sum));
}



int main(){
    string s;
    cin >> s;
    cout << solve(s) << endl;

    return 0;
}