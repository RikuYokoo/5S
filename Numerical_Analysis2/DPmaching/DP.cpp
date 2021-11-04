#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;
class DP{
  private:
    std::string filename;
  public:
    DP(){}

    int get_fream(const std::string filename, int I){
      int fream;
      cout << filename;
      string str;
      stringstream ss, str_int;
      std::vector<std::string> info;
      ss << filename << "/" << filename << "_" << std::setw(3) << std::setfill('0') << I+1 << ".txt";
      str = ss.str();
      std::ifstream fin(str);
      for(int i=0;i<3;i++){
        fin >> info.at(i);
        if(i==2){
          str_int << info.at(i);
          str_int >> fream;
        }
      }
      return fream;
    }
    };

int main(){
  std::vector<std::string> cit{"city011", "city012", "city021", "city022"};
  std::vector<std::vector<std::vector<string>>> stempleat(100);
  //std::vector<std::vector<std::vector<double>>> city_one(100), city_onetwo(100), city_two(100), city_twoone(100);
  std::vector<std::vector<std::vector<double>>> city_one, city_onetwo, city_two, city_twoone;
  city_one.resize(100);
  city_onetwo.resize(100);
  city_two.resize(100);
  city_twoone.resize(100);
  
  DP dp;
  cout << cit.at(0) << endl;
  cout << cit.at(1) << endl;
  cout << cit.at(2) << endl;
  cout << cit.at(3) << endl;
  cout << city_one.size() << endl;
    int p = dp.get_fream("city011",0);
    cout << p << endl;
  for(int i=0; i < 100;i++){
    //int p = dp.get_fream(cit.at(0),i);
    //int p = dp.get_fream("city011",i);
    //cout << p << endl;
    /*
    city_one.at(i).resize(dp.get_fream(cit.at(0), i));
    city_onetwo.at(i).resize(dp.get_fream(cit.at(1), i));
    city_two.at(i).resize(dp.get_fream(cit.at(2), i));
    city_twoone.at(i).resize(dp.get_fream(cit.at(3), i));
    */
  }
  //dp.get_fream(

  return 0;
}

