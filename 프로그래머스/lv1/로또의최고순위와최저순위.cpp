//lv1.로또의 최고 순위와 최저 순위
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt=0; //당첨번호와 같은 숫자 갯수
    int zero=0; //지워진 숫자 갯수
    int max_rank=0; //최고 순위
    int min_rank=0; //최저 순위

    for(int i=0; i<lottos.size() ; i++){
        if(lottos[i]==0){
            zero++;
            continue;
        }
        for(int j=0; j<win_nums.size(); j++){
                if(lottos[i]==win_nums[j])
                    cnt++;
        }
    }
    
    //min_rank 구하기
    if(cnt<=1)
        min_rank=6;
    else
        min_rank=7-cnt;
    
    
    //max_rank구하기
    if(cnt+zero>=6)
        max_rank=1;
    else if(cnt+zero==0 || cnt+zero==1)
        max_rank=6;
    else
        max_rank=7-(cnt+zero);
        
    answer.push_back(max_rank);
    answer.push_back(min_rank);
    
    return answer;
}