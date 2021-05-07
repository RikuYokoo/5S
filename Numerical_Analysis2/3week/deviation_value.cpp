#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Deviation_Value
{
private:
  double ave, s;
public:
  Deviation_Value():ave(0), s(0)
  {
  }
  ~Deviation_Value()
  {
  }
  void average(int data, int all_data){
    double sum = (double)data;
    ave = sum/(double)all_data;
    //cout << "ave = " << ave << endl;//
    //return ave;
  }
  void std_deviation(int data, int all_data)
  {
    int data_0 = 0;
    int diff_data = (data - ave)*(data - ave);
    if(all_data !=1){
      data_0 = ave * ave * (all_data-1);
    }
    double s_2 = (diff_data + data_0)/(double)all_data;
    s = std::sqrt(s_2);
    //cout << "s = " << s << endl;
    //return s;
  }
  double deviation(int data, int all_data)
  {
    average(data,all_data);
    std_deviation(data, all_data);
    double ans = (double)(data-ave)*10 / s  + 50;
    return ans;
  }
};

int main(){
  Deviation_Value devi;
  int data = 100, sum = 1;
  int all = 1000000;
  double hennsati=0;

  for(;sum<=all;sum++){
    hennsati = devi.deviation(data, sum);
    cout << hennsati << endl;
  }

  return 0;
}

