#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;
double local_distance(std::vector<double> fream_i, std::vector<double> fream_j);
double min3(double x, double y, double z);

int dpmaching(std::vector<std::vector<std::vector<double>>> &anser, std::vector<std::vector<double>> &detect){
  //cout << "detect=" << detect.size() << endl;
  double tmp=0, kai=0,r=0,m=0, l=0, min=0;
  int flag=0, flag2=0;
 // std::vector<std::vector<double>> total(anser.at(0).
  std::vector<double> zero(15,0);
  std::vector<double> ans(100);
  for(int i=0;i < 100;i++){
    //cout << "for\n";
    std::vector<std::vector<double>> total(anser.at(i).size(), std::vector<double>(detect.size()));
   // cout<<total.size() << total.at(0).size() << endl;
    //cout << "for\n";
    for(int j=0;j<anser.at(i).size();j++){
    //cout << "i=" << i << " j=" << j << endl;
      for(int k=0;k<detect.size();k++){
      //  cout << "i=" << i << " j=" << j << " k=" << k << endl;
        if(j==0 && k==0){
          total.at(0).at(0) = local_distance(zero,zero);
        }else if(j>0 && k-1 < 0){
          total.at(j).at(0) = total.at(j-1).at(k) + local_distance(anser.at(i).at(j),zero);
        }else if(k>0 && j-1 < 0){
          total.at(0).at(k) = total.at(0).at(k-1) + local_distance(zero, detect.at(k));
        }else{
          r = total.at(j).at(k-1) + local_distance(anser.at(i).at(j), detect.at(k));
          m = total.at(j-1).at(k-1) + 2 * local_distance(anser.at(i).at(j), detect.at(k));
          l = total.at(j-1).at(k) + local_distance(anser.at(i).at(j), detect.at(k));
          total.at(j).at(k) = min3(r, m, l);
          }
      }
    }
    ans.at(i) = total.at(anser.at(i).size()-1).at(detect.size()-1) / (double)(anser.at(i).size() + detect.size());
    tmp = ans.at(i);
    if(i==0) {
      min = ans.at(i);
      flag = i;
    }else if(min > tmp){
      min = tmp;
      flag = i;
    }
  }
  //cout << "end" << endl;
  return flag;

  //std::vector<std::vector<double>> local(anser.at(0).size(),std::vector<double> detect.at(0).size()
}

double local_distance(std::vector<double> fream_i, std::vector<double> fream_j){
  double ans=0, tmp=0, kai=0;
  for(int i=0;i<15;i++){
    tmp = fream_i.at(i)-fream_j.at(i);
    ans += tmp*tmp;
  }
  return sqrt(ans);
}

double min3(double x, double y, double z)
{
  double min = x;

  if (y < min) min = y;
  if (z < min) min = z;
  return (min);
}

std::string get_filename(std::string &filename, int I)
{
  std::stringstream ss;
  ss << filename << "/" << filename << "_"<< std::setw(3) << std::setfill('0') << I+1 << ".txt";
  return ss.str();
}
int get_fream(string &filename)
{
  int fream;
  std::stringstream ss;
  std::vector<std::string> info(3);
  std::ifstream fin(filename);
  for(int i=0;i<3;i++){
    fin >> info.at(i);
  }
  ss << info.at(2);
  ss >> fream;
  return fream;
}
void resize_vector(std::vector<std::vector<double>> &vvec, int fream)
{
  vvec.resize(fream);
}

void file_read(std::string filename, std::vector<std::vector<double>> &data)
{
  std::ifstream fin(filename);
  std::vector<std::string> dev(3);
  for(int i=0;i<data.size();i++){
    for(int j=0;j<15;j++){
      std::stringstream ss;
      double tem;
      if(i==0){
        fin >> dev.at(0);
        fin >> dev.at(1);
        fin >> dev.at(2);
      }
      vector<string> str(1);
      fin >> str.at(0);
      ss << str.at(0);
      ss >> tem;
      data.at(i).push_back(tem);
    }
  }
}

int main(){
  int flag=0, flag2=0;
  std::vector<int> fream(4,0);
  std::vector<std::vector<std::vector<std::vector<double>>>> templeat_data(4), detect_data(4);
  for(int i=0;i<4;i++){
    templeat_data.at(i).resize(100);
    detect_data.at(i).resize(100);
  }
  std::vector<std::string> city{"city011", "city012", "city021", "city022"};
  double ans=0;
  std::vector<string> str1(3), str2(3);
  for(int I=0;I<100;I++){
    for(int i=0;i<4;i++){
      std::vector<string> info(3),info2(3),dev(4);
      stringstream ss,ss2;
      stringstream stod, stod2;
      std::vector<std::string> filename(4);
      filename.at(i) = get_filename(city.at(i), I);
      fream.at(i) = get_fream(filename.at(i));
      resize_vector(templeat_data.at(i).at(I), fream.at(i));
      resize_vector(detect_data.at(i).at(I), fream.at(i));
      file_read(filename.at(i), templeat_data.at(i).at(I));
      file_read(filename.at(i), detect_data.at(i).at(I));
      cout << I << endl;
    }
  }
//  cout << "start!" << endl;
//  cout << "detect=" << detect_data.size() << endl;
  /*
  for(int i=0;i<100;i++){
    flag = dpmaching(templeat_data, detect_data.at(i));
    if(flag == i) flag2++;
    cout << "end:" << i << endl;
  }
  */
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      for(int k=0;k<100;k++){
        if(!(i==j)){
          flag = dpmaching(templeat_data.at(i), templeat_data.at(j).at(k));
      //    cout << "flag = " << flag << " K = " << k << " ";
          if(flag == k) flag2++;
        }
      }
      if(!(i==j)){
        cout << endl;
        std::cout << "templeat is " << city.at(i) << "detect is " << city.at(j) << std::endl;
        std::cout << "recognation rate is " << flag2 << std::endl;
        flag2 = 0;
      }
    }
  }
 // cout << flag2 << endl;
  return 0;
}

