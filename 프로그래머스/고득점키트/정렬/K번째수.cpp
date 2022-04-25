#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0; i<commands.size(); i++){ //commands 갯수만큼 반복(행갯수)
        vector <int> v;
        
        int start_idx=commands[i][0]; //시작 인덱스
        int end_idx=commands[i][1]; //끝 인덱스
        int k=commands[i][2]; //찾고자 하는 인덱스
        for(int j=start_idx-1; j<end_idx; j++){
            v.push_back(array[j]);            
        }
        
        sort(v.begin(),v.end());
        int result = v[k-1];
        answer.push_back(result);
    }
    
    
    return answer;
}