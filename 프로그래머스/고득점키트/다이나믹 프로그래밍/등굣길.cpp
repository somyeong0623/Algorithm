//학생때 배운 최단경로 공식을 이용
#include <string>
#include <vector>
#include <iostream>
#define mod 1000000007

using namespace std;
bool p[101][101]; // 물에잠긴 좌표는 true
int d[101][101];
bool row_flag;
bool col_flag;

//n이 행, m이 열
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    //물에잠긴 지역 처리
    for(int i=0; i<puddles.size(); i++){
        int x=puddles[i][1];
        int y=puddles[i][0];
        
        p[x][y]=true;
    }    
    
    //시작좌표 0, 시작좌표를 제외한 첫번째 행과 첫번째열을 1로 초기화
    d[1][1]=0;
    //첫번째 행 초기화
    for(int i=2; i<=m; i++){
        if(p[1][i]){// p[1][i]지점이 물에잠겼으면 그 지점과, 그 이후 지점은 최단경로로 갈 수 없으므로 0으로 초기화
            d[1][i]=0;
            row_flag=true;
        }
        if(row_flag==true)
            d[1][i]=0;
        else
            d[1][i]=1;
    }
    
    //같은 방식으로 첫번째 열 초기화
     for(int i=2; i<=n; i++){
        if(p[i][1]){
            d[i][1]=0;
            col_flag=true;
        }
        if(col_flag==true)
            d[i][1]=0;
        else
            d[i][1]=1;
    }
    
 
    //최단경로 공식 적용
    for(int i=2; i<=n; i++){
        for(int j=2; j<=m; j++){
            if(p[i][j]==true){
                d[i][j]=0;
                continue;
            }
            d[i][j]=(d[i-1][j]+d[i][j-1])%mod;
        }
    }
    
    
    return d[n][m];
}