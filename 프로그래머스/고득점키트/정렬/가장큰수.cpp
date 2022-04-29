/*풀이 방법
numbers수들을 string으로 바꾼뒤, 각 string 사이즈만큼 돌면서 모든 숫자를 char형벡터에 넣는다.
벡터를 내림차순으로 정렬하고, 그것을 이어붙여 string으로 만든뒤 리턴.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(string a,string b){ //3,30이 있을때, string순서로는 30, 3 이지만 303<330 이므로 3이 앞에오게끔 해야함.
        return a+b>b+a;
}


string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> v;
    vector<int> num;
    
    for(int i=0; i<numbers.size(); i++){
        string cur=to_string(numbers[i]);
        v.push_back(cur);
    }
        
    sort(v.begin(),v.end(),cmp);
    
    //만약 numbers=[0,0,0] 이면 답은 "000"이아니라 "0"이 되어야한다. 왜냐면 answer은 만들수 있는 가장 큰수를 문자열로 나타내기만 한것이므로 000이런건 없다. 
    //그러므로 answer=="0"이고 v[i]=="0"이면 answer은 그냥 "0"으로 설정해주어야 함.
    
    for(int i=0; i<v.size(); i++){
        if(answer=="0" && v[i]=="0"){ 
         answer="0";
        }else{
        answer+=v[i];
        }
    }
    
    
    return answer;
}