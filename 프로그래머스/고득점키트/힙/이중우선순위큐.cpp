//이중 우선순위 큐
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
풀이방법
우선순위 큐 문제인데 큐 안씀 ,,,
벡터에 숫자들을 삽입함.
삭제 명령이 있을때마다 최댓값삭제인지 최솟값 삭제인지에 따라 벡터를 정렬 혹은 역순정렬해서 마지막값 삭제
answer벡터에 요구하는 값 삽입.

*/

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> v;

    
    for(int i=0; i<operations.size(); i++){
        string now_string=operations[i];
        char oper=now_string[0];
        
        if(oper=='I'){ //벡터에 숫자 삽입
            int num=stoi(now_string.substr(2));  //substring의 두번째 인자 생략하면 끝까지를 뜻함.
            v.push_back(num);
            
        }else if(oper=='D'){
            if(v.size()>0){ //벡터가 않을때만 삭제 명령 수행
                int check=stoi(now_string.substr(2));
                if(check==1){ //벡터에 최댓값 삭제
                    sort(v.begin(),v.end()); //정렬한 후 벡터의 제일 끝 값 삭제
                    v.pop_back();
                
                }else{ //check==-1, 벡터에서서 최솟값 삭제
                    sort(v.rbegin(), v.rend()); //역순 정렬 한 후, 제일 끝 값 삭제
                    v.pop_back();
                }
            }
        }
        
    }

    if(v.size()==0){
        answer.push_back(0);
        answer.push_back(0);
    }else{
        sort(v.begin(),v.end());
        answer.push_back(v.back()); //최댓값 삽입
        answer.push_back(v.front());// 최솟값 삽입
        
    }
    
    return answer;
}