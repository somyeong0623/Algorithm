/*
[풀이 방법]
가로 길이 m, 세로 길이 n이라고 할때, m과 n의 연립방정식이 나온다

1.테두리를 보면 가로길이-1와 세로 길이-1이 두번 존재하는 것이므로 
((m-1)+(n-1))*2= brown -> m+n=brown/2 +2
2. brown+yellow = m*n

이 두 식을 통해 m,n을 찾으면 된다.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int m=0,n=0; //가로:m, 세로:n
        while(true){  //입력값이 답이 구할수 있는 형태로만 주어진다고 가정해서 true로 돌림.
            m++; // 헤맨부분. m++을 while문의 마지막에 넣으면 continue로인해 m++에 도달하지 못하는경우로 인해 시간초과 발생
            
            if((brown+yellow)%m!=0) //n이 정수로 나누어떨어지지 않으면 continue
                continue;
            n=(brown+yellow)/m; //2번 방정식을 이용해 n구하기
            
            if((m+n)==(brown/2+2)){ // 1번 방정식까지 성립하면 조건에 맞는 m,n구한것이므로 answer에 푸쉬하고 리턴
                
                if(m>n){ //가로길이는 세로길이와 같거나 더 길다.
                answer.push_back(m);
                answer.push_back(n);
                }else{
                    answer.push_back(n);
                    answer.push_back(m);
                     
                }
                return answer;
            }
        }
}