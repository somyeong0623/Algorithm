//16926번: 배열 돌리기 1
/*
반시계방향으로 R번 회전시킨 결과 출력

2 ≤ N, M ≤ 300
1 ≤ R ≤ 1,000
min(N, M) mod 2 = 0
1 ≤ Aij ≤ 108

## 풀이방법
배열을 입력받는다.
테두리부터 0번째 그룹부터 min(n,m)/2번째 그룹까지 나눈다. ->2차원 벡터
그룹별로 각각 R번 회전시킨 값을 배열에 넣는다
배열을 출력한다

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,r;//행, 열, 횟수
int arr[300][300];

vector<vector<int>> v; 

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>r;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

   // 그룹 나누기
   int group_cnt=min(n,m)/2; //algorithm 헤더 필요
   for(int k=0; k<group_cnt; k++){
       vector<int> group;

       //사각형 테두리 ㅁ 를 위에부터 시계방향으로 1,2,3,4번이라하자. 네 좌표가 겹치니까 각각 테두리에서 끝에 하나씩은 빼야하는것 주의
       for(int i=k; i<m-1-k; i++){ //1번 테두리 . i<=m-1-k인데 겹치는거 뺴기위해 =는 생략
           group.push_back(arr[k][i]); 
       }

       for(int i=k; i<n-1-k; i++){ //2번 테두리 
            group.push_back(arr[i][m-1-k]);
       }

       for(int i=m-1-k; i>k; i--){ //3번 테두리 
           group.push_back(arr[n-1-k][i]);
       }

       for(int i=n-1-k; i>k; i--){ //4번 테두리
           group.push_back(arr[i][k]);
       }

       v.push_back(group);
    }   

    // r번 회전 하기
    // 이때, for문 돌리는 순서는 위에와 완전히 동일해야한다.
    for(int k=0; k<group_cnt; k++){
        vector<int>& group=v[k];
        int len=group.size();
        int index=r%len;
        
        for(int i=k; i<m-1-k; i++, index=(index+1)%len){ //1번 테두리  
           arr[k][i]=group[index];
       }

       for(int i=k; i<n-1-k; i++, index=(index+1)%len){ //2번 테두리
            arr[i][m-1-k]=group[index];
       }

       for(int i=m-1-k; i>k; i--, index=(index+1)%len){ //3번 테두리
           arr[n-1-k][i]=group[index];

       }

       for(int i=n-1-k; i>k; i--, index=(index+1)%len){ //4번 테두리
            arr[i][k]=group[index];
       }
        
    }

    // cout<<"-------"<<"\n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
   
    


}