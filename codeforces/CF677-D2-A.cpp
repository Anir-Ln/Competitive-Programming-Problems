#include <iostream>
#include <cmath>

using namespace std;


int main(){
  
  int n, m, a;
  cin >> n >> m >> a;
  
  cout << ceil(n/a) * ceil(m/a) << endl; 
  
  return 0;
}