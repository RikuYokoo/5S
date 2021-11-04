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
  cout << "end" << endl;
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

int fream_get(string filename)
{
}
void file_read()
{
}

int main(){
  int flag=0, flag2=0;
  std::vector<std::vector<std::vector<double>>> templeat_data(100), detect_data(100);
  double ans=0;
  std::vector<string> str1(3), str2(3);
  for(int I=0;I<100;I++){
    std::vector<string> info(3),info2(3),dev(4);
    stringstream ss,ss2;
    stringstream stod, stod2;
    double fream,fream2;
    std::string filename, filename2;
    ss << "city022/" << "city022_" << std::setw(3) << std::setfill('0') << I+1 << ".txt";
    ss2 << "city021/" << "city021_" << std::setw(3) << std::setfill('0') << I+1 << ".txt";
    filename = ss.str();
    filename2 = ss2.str();
    std::ifstream fin(filename);
    std::ifstream fin2(filename2);
    //cout << filename << endl;
    for(int i=0;i<3;i++){
      //cout << "while" << endl;
      fin >> info.at(i);
      fin2 >> info2.at(i);
    }
    //cout << info.at(2) << endl;
    //cout << info2.at(2) << endl;
    //cout << "for end" << endl;
    stod << info.at(2);
    stod >> fream;
    stod2 << info2.at(2);
    stod2 >> fream2;
    //cout << info.at(1);
    //cout << fream << endl;
    templeat_data.at(I).resize(fream);
    detect_data.at(I).resize(fream2);
    fin.close();
    fin2.close();
    fin.open(filename);
    fin2.open(filename2);
    //dev.push_back(info.at(0));
    //cout << dev.at(0) << endl;
    for(int i=0;i<fream;i++){
      for(int j=0;j<15;j++){
        stringstream ss;
        double tem;
        if(i==0){
          fin >> dev.at(0);
          fin >> dev.at(1);
          fin >> dev.at(2);
          //cout << dev.at(3) << endl;
        }
        vector<string> str(1);
        fin >> str.at(0);
        ss << str.at(0);
        //cout << str.at(0);
        ss >> tem;
        //cout << tem << endl;
        templeat_data.at(I).at(i).push_back(tem);
      }
    }
    for(int i=0;i<fream2;i++){
      for(int j=0;j<15;j++){
        stringstream ss;
        double tem;
        if(i==0){
          fin2 >> dev.at(0);
          fin2 >> dev.at(1);
          fin2 >> dev.at(2);
        }
        vector<string> str(1);
        fin2 >> str.at(0);
        ss << str.at(0);
        ss >> tem;
        detect_data.at(I).at(i).push_back(tem);
      }
    }
    cout << I << endl;
  }
//  cout << "start!" << endl;
//  cout << "detect=" << detect_data.size() << endl;
  for(int i=0;i<100;i++){
    flag = dpmaching(templeat_data, detect_data.at(i));
    if(flag == i) flag2++;
    cout << "end:" << i << endl;
  }
  cout << flag2 << endl;
  return 0;
}

