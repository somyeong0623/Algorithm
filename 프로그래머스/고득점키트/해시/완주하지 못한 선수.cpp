#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for(auto i: participant){
        m[i]++;
    }
    
    for( auto i:completion){
        m[i]--;
    }
    
    for(auto i:participant){
        if(m[i]==1){
            answer=i;

        }
    }
    
    return answer;
}