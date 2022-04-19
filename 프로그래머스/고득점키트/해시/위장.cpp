#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string,int> map;
    for(int i=0; i<clothes.size(); i++){
        map[clothes[i][1]]++;
    }
    
    int answer = 1;
    for(auto i : map){
        answer*=(i.second+1);
    }    

    return answer-1;
}