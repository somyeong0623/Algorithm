//1541. 잃어버린 괄호 (답보고 이해함)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int answer;//정답
int sign=1;

int main(){
    string s;
    cin>>s;

    string tmp="";

    for(int i=0; i<s.size(); i++){
      if(s[i]=='+'){
          int num=stoi(tmp);
          answer+=sign*num;
          tmp="";
      }else if(s[i]=='-'){ //-가 나오면 그이후로는 다 뺄셈처리 해주면 된다.
          int num=stoi(tmp);
          answer+=sign*num;
          tmp="";
          sign=-1; //순서 주의. -가 처음 나오기 전까지 부호는 +로 처리해주어야 한다.
      }else{
          tmp+=s[i];
      }

    }
    //string마지막엔 숫자이므로, 마지막값도 벡터에 push 해야함.
    int num=stoi(tmp);
    answer+=sign*num;

    cout<<answer<<"\n";
}