#include <iostream>


using namespace std;



int main(){

    int n, a;
    cin >> n >> a;
    a--;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int i=a+1;
    int j=a-1;
    // initialize count withh # of criminials in current city
    int count = arr[a];

    // count all crminial in cityes that we're sure about, e.g cities which are both far with the same distance 
    while(i<n && j>=0){
        if(arr[i] && arr[j]){
            count += 2;
        }
        i++;
        j--;
    }

    // count criminals in cities that have no symetric city relatively to the city of the policeman
    while(i<n){
        count += arr[i];
        i++;
    }
    while(j>=0){
        count += arr[j];
        j--;
    }

    cout << count << endl;

    return 0;
}