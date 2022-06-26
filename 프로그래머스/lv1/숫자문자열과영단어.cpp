//lv1: 숫자 문자열과 영단어
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string num_english[]={"zero","one","two","three","four","five","six",
             "seven","eight","nine"}; //영어숫자(문자열) 배열
string num[]={"0","1","2","3","4","5","6",
             "7","8","9"}; //숫자(문자열) 배열

string isNum(string s){ //현재 문자열이 영어숫자 혹은 숫자에 해당하는지 확인
    for(int i=0; i<10; i++){
        if(s==num_english[i]){ //영어숫자에 해당하면 숫자(문자열)로 바꿔서 반환
            return to_string(i);
        }
    }
    for(int i=0; i<10; i++){ //숫자에 해당하면 그대로 숫자(문자열) 반환
        if(s==num[i])
            return s;
    }
    return "NO"; //숫자 혹은 영어숫자에 해당안되는 문자열이면 'NO'반환
}


int solution(string s) {
    int answer = 0;
    string s_answer="";
    string temp="";
    int s_size=s.size();
    for(int i=0;i<s_size; i++){
        temp+=s[i];
        if(isNum(temp)!="NO"){
            s_answer+=isNum(temp); 
            temp=""; //temp 비우기
        }
    }
    answer=stoi(s_answer); //string->int 변환
    return answer;
}