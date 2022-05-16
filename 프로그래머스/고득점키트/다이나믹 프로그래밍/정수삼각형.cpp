//프로그래머스: 정수 삼각형
/*
풀이

입력받은 벡터의 좌표를 이차원 벡터라고 생각하고 보면
triangle[0][0], triangle[1][0], triangle[1][1], triangle[2][0], triangle[2][1], triangle[2][2]... 와 같다.
각 좌표의 최댓값을 d[i][j]라고 하자. (인덱스 0부터 시작)

d[i][j]를 찾는 과정
1) j==0 일 때 (왼쪽 끝 값)
d[i][j]=d[i-1][0]+triangle[i][j]
2) j==i-1 일 때 (오른쪽 끝 값))
d[i][j]=d[i-1][j-1]+triangle[i][j]
3) j가 그 외의 값일 때
d[i][j]=max(d[i-1][j-1], d[i-1][j])+triangle[i][j] 

답은 d[n-1][0],d[n-1][1],,,d[n-1][n-1]중에서 최댓값이 된다.

*/

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
int d[501][501];



int solution(vector<vector<int>> triangle) {
    int answer=0;
    d[0][0]=triangle[0][0];
    
    
    if(triangle.size()==1){
        return triangle[0][0];
    }

    
    for(int i=1; i<triangle.size(); i++){
        for(int j=0; j<=i; j++){
           if(j==0){
               d[i][j]=d[i-1][0]+triangle[i][j];
           }else if(j==i){
               d[i][j]=d[i-1][j-1]+triangle[i][j];
           }else{
               d[i][j]=max(d[i-1][j-1]+triangle[i][j], d[i-1][j]+triangle[i][j]);
           }
        }
    }
    
    int n=triangle.size();
    
    for(int i=0; i<triangle.size(); i++){
        if(answer<d[n-1][i]){
            answer=d[n-1][i];
        }
    }
    
    return answer;
}