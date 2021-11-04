#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<vector<vector<int>>> vec;
  vec.resize(10);
  vec.at(1).resize(5);
  vec.at(1).at(1).resize(5);


  return 0;
}

