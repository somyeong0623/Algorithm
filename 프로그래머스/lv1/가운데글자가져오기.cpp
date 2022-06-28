//lv1. 가운데 글자 가져오기
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int s_size=s.size();
    if(s_size%2==1){//크기가 홀수면
        answer+=s[s_size/2];
    }else{//크기가 짝수면
        answer+=s[s_size/2-1];
        answer+=s[s_size/2];
    }
    
    return answer;
}