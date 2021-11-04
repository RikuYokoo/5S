#include <iostream>
#include <string>
#include <vector>

class Matching{
private:
  std::string str;
  std::vector<bool> flag;
  bool fl,fl2;
  std::string maru, batu;
  int kurikaesi;
  int num;
public:
  Matching()
  {
    maru = 'o';
    batu = 'x';
    num=1;
    fl=false;
    fl2=false;
  }
  ~Matching()
  {
  }
  std::string input_string()
  {
    std::cout << "string" << num << ":";
    std::cin >> str;
    num++;
    return str;
  }
  void comparison_string_length(std::string &str1, std::string &str2)
  {
    int size = str1.size() - str2.size();
    int num=0;
    fl = (size < 0);

    while(!(str1.size() == str2.size())){
      if(fl){
        str1.push_back(' ');
      }else{
        str2.push_back(' ');
      }
    }
    kurikaesi = str1.size();
    if(fl){
      str1.swap(str2);
    }
    if(size == 0){
      for(int i=0;i<str1.size();i++){
        flag.push_back( str1.at(i) == str2.at(i));
      }
    }else{
      for(int i=0;i<str1.size();i++){
        if(!(str1.at(i) == str2.at(i))){
          num=i;
          break;
        }
      }
      /*--------一個づつづらしている--------------*/
      for(int i=str1.size()-1;i>num;i--){
        str2.at(i) = str2.at(i-1);
        str2.at(i-1) = ' ';
      }
      for(int i=0;i<str1.size();i++){
        if(!(str1.at(i) == str2.at(i))){
          if(num < i){
            num = i;
            fl2 = true;
            break;
          }
        }
      }
      if(fl2){
        for(int i=str1.size()-1;i>num;i--){
          str2.at(i) = str2.at(i-1);
          str2.at(i-1) = ' ';
        }
      }

      for(int i=0;i<str1.size();i++){
        flag.push_back( str1.at(i) == str2.at(i));
      }
    }
    if(fl){
      str1.swap(str2);
    }
  }

  void output_marubatu(){
    for(int i=0;i<kurikaesi;i++){
      if(flag.at(i)){
        std::cout << maru << " ";
      }else{
        std::cout << batu << " ";
      }
    }
    std::cout << std::endl;
  }
  void output_string(std::string out){
    for(int i=0;i<out.size();i++){
      std::cout << out.at(i) << " ";
    }
    std::cout << std::endl;
  }
};
int main(){
  std::string str1, str2;
  Matching match;
  str1 = match.input_string();
  str2 = match.input_string();

  match.comparison_string_length(str1, str2);

  match.output_string(str1);
  match.output_string(str2);

  match.output_marubatu();

  return 0;
}

