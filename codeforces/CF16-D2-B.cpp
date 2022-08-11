#include <iostream>
#include <algorithm>


using namespace std;

bool cmp(int *a, int *b){
    return a[1] > b[1];
}


int main(){
    int n, m;
    cin >> n >> m;
    // m = #containers
    // n = # can take
    int **arr = new int*[m];
    for(int i=0; i<m; i++)
        arr[i] = new int[2];

    for(int i=0; i<m; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

    // sort arr by second element (#of matches in matchbox)
    sort(arr, arr+m, cmp);

    int count = 0;
    // take the matchboxes with the highest matches first.
    for(int i=0; i<m; i++){
        int can = n - arr[i][0];
        // if can >= 0 means if we take all the matchboxes in ith-matchbox and take the left "can" boxes from the the next containers
        if(can >= 0){
            count += arr[i][1]*arr[i][0];
        }
        else  {
            /// we take all the remaining needed boxes from this container  
            count += arr[i][1]*n;
            break;
        }
        n = can;
    }

    cout << count << endl;
    
    return 0;
}