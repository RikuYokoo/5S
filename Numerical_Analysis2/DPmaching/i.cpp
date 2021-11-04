#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){

  std::ifstream fin("city011/city011_001.txt");
  int num=0;
  while(!(fin.fail())){//input 
    if(num==1) break;
    num++;
  }
  return 0;
}

