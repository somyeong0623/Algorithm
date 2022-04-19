#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int index=0;
    int cnt=0;
    int sum=0;
    while(true){
        for(int i=0; i<progresses.size(); i++){
              progresses[i]+=speeds[i];
        } 
        cnt=0;
            if(progresses[index]>=100){
                for(int j=index; j<progresses.size(); j++){
                    if(progresses[j]>=100){
                        cnt++;
                        if(j==progresses.size()-1){
                            answer.push_back(cnt);
                            sum+=cnt;
                            break;
                        }
                    }else{
                        index=j;
                        answer.push_back(cnt);
                        sum+=cnt;
                        break;
                    }
                }
            }
         if(sum==progresses.size()){
            break;
        }
            
        }
    
    return answer;
}