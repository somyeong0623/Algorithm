//lv1. 다트 게임
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = 0;
    int s_size=s.size();
    vector<int> score(3,0); 
    vector<char> bonus(3,' ');
    vector<char> option(3,' ');
    vector<int> tmp(3,0);//각 index에 해당하는 최종점수
    
    int index=0;
    for(int i=0; i<s_size; i++){
        if(s[i]>='0' && s[i]<='9'){//score
            if(s[i+1]=='0'){//점수가 두자리인 경우(10인경우) 따로 분리
                score[index]=10;
                i++;//문자2개 확인했으니까 i++해줘야함
            }else{
                score[index]=(s[i]-'0'); //char->int 변환
            }
        }else if(s[i]=='S'||s[i]=='D'||s[i]=='T'){ //bonus
            bonus[index]=s[i];
            index++; //bonus는 반드시3개나오니까 이때 index++해놓고 뒤에 option이 있다면 그 옵션은 index-1번째에 넣으면 된다.
        }else{
            option[index-1]=s[i];
        }
    }
    
    for(int i=0; i<3; i++){
        int cur_score=score[i];
        char cur_bonus=bonus[i];
        char cur_option=option[i];
        
        if(cur_bonus=='S')
            tmp[i]=pow(cur_score,1);
        else if(cur_bonus=='D')
            tmp[i]=pow(cur_score,2);
        else //T
            tmp[i]=pow(cur_score,3);
        
        if(cur_option=='#')
            tmp[i]=-tmp[i];
        else if(cur_option=='*'){
            tmp[i]*=2;
            if(i-1>=0){
                tmp[i-1]*=2;
            }
        }
    }
    for(int i=0; i<3; i++){
        answer+=tmp[i];
        // cout<<"tmp[i]: "<<tmp[i]<<"\n";
    }
    
    return answer;
}