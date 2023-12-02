#include <iostream>
// The following library needs to be included to use std::sort()
#include <algorithm>
using namespace std;

int main() {
  string coffee[] = {"latte", "cappuccino", "americano", "espresso"}; 
  int size = 4;
  std::sort(coffee, coffee + size);
  for (int i = 0; i < 4; i++){
    cout<<coffee[i]<<endl;
  }
  return 0;
}