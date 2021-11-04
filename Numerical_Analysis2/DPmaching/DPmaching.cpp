#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;
class DPmaching{
  private:
    int I, dimension;
    std::vector<std::string> filename, filename2;
    std::stringstream ss, ss2, stod, stod2;
    std::vector<int> templeat_fream, detect_fream;
    std::vector<std::vector<std::vector<string>>> stempleat, sdetect;
    std::vector<std::vector<std::vector<double>>> templeat_data, detect_data;
    //std::vector<std::vector<std::vector<string>>> sdetect;
    //std::vector<std::vector<std::vector<double>>> detect;
    std::vector<std::vector<string>> templeat_voice, detect_voice;
    std::vector<std::string> info, info2;
  public:
    DPmaching(){
      templeat_voice.resize(100);
      detect_voice.resize(100);
      templeat_fream.resize(100);
      detect_fream.resize(100);
      stempleat.resize(100);
      sdetect.resize(100);
      templeat_data.resize(100);
      detect_data.resize(100);
      dimension=15;
      filename.resize(100);
      filename2.resize(100);
      info.resize(3);
      info2.resize(3);
    }
    ~DPmaching(){}

    void get_fream_and_voice_data()//引数にファイル名を渡せばいいようにすればいい？
    {
      //std::string info(3), info2(3);
      for(I=0; I<100;I++){
        ss.str("");
        ss2.str("");
        ss << "city011/" << "city011_" << std::setw(3) << std::setfill('0') << I+1 << ".txt";
        ss2 << "city012/" << "city012_" << std::setw(3) << std::setfill('0') << I+1 << ".txt";
        filename.at(I) = ss.str();
        filename2.at(I) = ss2.str();
        std::ifstream fin(filename.at(I));
        if(!fin)std::cerr << "error can't open file" << std::endl;
        std::ifstream fin2(filename2.at(I));
        if(!fin2)std::cerr << "error can't open file" << std::endl;
        for(int i=0;i<3;i++){
          fin >> info.at(i);
          fin2 >> info2.at(i);
            cout << info.at(i) << endl;
          //if(i==1){
            //templeat_voice.at(I) = info.at(i);
            //detect_voice.at(I) = info2.at(i);
            //templeat_voice.at(I) = info;
            //detect_voice.at(I) = info2;
          //}
          if(i==2){
            cout << "if==2" << endl;
            stod << info.at(i);
            //cout << info.at(i) << endl;
            stod >> templeat_fream.at(I);
            stod2 << info2.at(i);
            stod2 >> detect_fream.at(I);
  //          cout << templeat_fream.at(I)<< endl;;
          }
          cout << i << endl;
        }
        cout << "end" << endl;
        cout << "koko";
        for(int i=0;i<detect_fream.at(I);i++){
          detect_data.at(I).push_back(fin);
        }
        //templeat_data.at(I).resize(templeat_fream.at(I));
        //templeat_data[I].resize(templeat_fream.at(I));
        //stempleat.at(I).resize(templeat_fream.at(I));
        //detect_data.at(I).resize(detect_fream.at(I));
        //sdetect.at(I).resize(detect_fream.at(I));
        cout << "qiu";
        for(int i=0; i < templeat_fream.at(I);i++){
          templeat_data.at(I).at(i).resize(dimension);
          stempleat.at(I).at(i).resize(dimension);
        }
        for(int i=0; i < templeat_fream.at(I);i++){
          detect_data.at(I).at(i).resize(dimension);
          //sdetect.at(I).at(i).resize(dimension);
        }
        //ベクトルのリサイズ
        /*
        templeat_data.at(I).resize(templeat_fream.at(I)).resize(dimension);
        stempleat.at(I).resize(templeat_fream.at(I)).resize(dimension);
        detect_data.at(I).resize(detect_fream.at(I)).resize(dimension);
        sdetect.at(I).resize(detect_fream.at(I)).resize(dimension);
        */

            //cout << templeat_fream.at(I)<<endl;
        for(int i=0;i < templeat_fream.at(I);i++){
          for(int j=0;j < dimension;j++){
            //cout << "haitteru?"<<endl;
            std::stringstream kari;
            fin >> stempleat.at(I).at(i).at(j);
            kari << stempleat.at(I).at(i).at(j);
            kari >> templeat_data.at(I).at(i).at(j);
          }
        }
        for(int i=0;i < detect_fream.at(I);i++){
          for(int j=0;j < dimension;j++){
            std::stringstream kari;
            fin2 >> sdetect.at(I).at(i).at(j);
            kari << sdetect.at(I).at(i).at(j);
            kari >> detect_data.at(I).at(i).at(j);
          }
        }
      }
    }

    void all_output()
    {
      for(int i=0;i < 100;i++){
        for(int j=0;j<detect_fream.at(i);j++){
          for(int k=0; k < dimension; k++){
            std::cout << detect_data.at(i).at(j).at(k);
          }
          std::cout << std::endl;
        }
      }
      std::cout << std::endl;
      std::cout << std::endl;
    }

    /*
    void resize_vector()//引数にリサイズしたいベクトルの参照をわたしておけばいい？
    {
      for(int i=0;i<templeat_data.size();i++){
        templeat_data.at(i).resize(templeat_fream.at(i)).resize(dimension);
        stempleat.at(i).resize(templeat_fream.at(i)).resize(dimension);
      }
      for(int i=0;i<detect_data.size();i++){
        detect_data.at(i).resize(detect_fream.at(i)).resize(dimension);
        sdetect.at(i).resize(detect_fream.at(i)).resize(dimension);
      }
    }
    */
};


int main(){
  DPmaching dp;

  dp.get_fream_and_voice_data();
  cout << "owatta" << endl;
  //dp.all_output();


  return 0;
}

