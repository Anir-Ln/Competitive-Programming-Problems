#include <iostream>
#include <vector>


using namespace std;


int main(){
  int n;
  cin >> n;

  int arr[n];
  vector<vector<int>> count(n, vector<int> (2)); /// 0 -> left, 1 -> right
  for(int i=0; i<n; i++){
    cin >> arr[i];
    
  }

  // count[i][0] = # of successive left elements <= arr[i]
  for(int i=1; i<n; i++)
    if(arr[i] >= arr[i-1])
      count[i][0] = 1 + count[i-1][0];

  // count[i][1] = # of successive right elements <= arr[i]
  for(int i=n-2; i>=0; i--){
    if(arr[i] >= arr[i+1])
      count[i][1] = 1 + count[i+1][1];
  }

  int mx = 0;
  // take the sum of left and right counts and take the max over all arr[i]
  for(int i=0; i<n; i++){
    mx = max(mx, count[i][0] + count[i][1]);
  }

  // add 1 which represents the arr[i] itself 
  // left + right + self
  cout << mx +1 << endl;

  return 0;
}