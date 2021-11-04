#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
  //std::stringstream ss;
  //std::string filename;
  std::vector<string> str1(3), str2(3);
  for(int i=1;i <= 1;i++)
  {
    std::stringstream ss, ss2;
    std::string filename, filename2;
    ss << "city011/" << "city011_" << std::setw(3) << std::setfill('0') << i << ".txt";
    ss2 << "city012/" << "city012_" << std::setw(3) << std::setfill('0') << i << ".txt";
    filename = ss.str();
    filename2 = ss2.str();
    cout << filename << " " <<  filename2 << endl;
    std::ifstream fin(filename);
    std::ifstream fin2(filename2);
    fin >> str1.at(i);
    fin2 >> str2.at(i);
    std::cout << str1.at(i) << str2.at(i) << endl;
  }

  return 0;
}
