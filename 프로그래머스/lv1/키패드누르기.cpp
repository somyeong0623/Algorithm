//lv1. 키패드 누르기
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> v(12,vector<int>(12,0)); //v[10][10] 0으로 초기화

string solution(vector<int> numbers, string hand) {
    v[2][1]=1; v[2][4]=2; v[2][7]=3; v[2][3]=1; v[2][6]=2; v[2][9]=3; 
    v[2][2]=0; v[2][5]=1; v[2][8]=2; v[2][0]=3; v[2][10]=4; v[2][11]=4;
    v[5][1]=2; v[5][4]=1; v[5][7]=2; v[5][3]=2; v[5][6]=1; v[5][9]=2;
    v[5][5]=0; v[5][2]=1; v[5][8]=1; v[5][0]=2; v[5][10]=3;  v[5][11]=3;
    v[8][1]=3; v[8][4]=2; v[8][7]=1; v[8][3]=3; v[8][6]=2; v[8][9]=1;
    v[8][8]=0; v[8][2]=2; v[8][5]=1; v[8][0]=1; v[8][10]=2; v[8][11]=2;
    v[0][1]=4; v[0][4]=3; v[0][7]=2; v[0][3]=4; v[0][6]=3; v[0][9]=2;
    v[0][0]=0; v[0][2]=3; v[0][5]=2; v[0][8]=1; v[0][10]=1; v[0][11]=1;
    //*=10, #=11
    
    
    string answer = "";
    int numbers_size=numbers.size();
    int cur_left=10; int cur_right=11; //왼손, 오른손 엄지의 현재위치(*, #)
    
    for(int i=0; i<numbers_size; i++){
        int cur_num=numbers[i];
        if(cur_num%3==1){//1,4,7
            answer+="L";
            cur_left=cur_num;
        }else if(cur_num%3==0 && cur_num!=0){ //3,6,9
            answer+="R";
            cur_right=cur_num;
        }else{//2,5,8,0
            if(v[cur_num][cur_right]==v[cur_num][cur_left]){ //거리 같을경우
                if(hand=="right"){//오른손잡이일 경우
                    answer+="R";
                    cur_right=cur_num;
                }else{//왼손잡이일경우
                    answer+="L";
                    cur_left=cur_num;
                }
            }else if(v[cur_num][cur_right]<v[cur_num][cur_left]){//거리 다르면 거리적은쪽으로 지정.
                answer+="R";
                cur_right=cur_num;
            }else{
                answer+="L";
                cur_left=cur_num;
            }
        }
    }
    return answer;
}