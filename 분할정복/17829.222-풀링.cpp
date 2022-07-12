//17829번. 222-풀링
/*
N(2<=N<=1024)
N은 2의 거듭제곱
행렬의 모든성분: -10,000이상 10,000이하 정수


*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1025][1025];
int n;
int cnt;
int a=2;

vector<int> tmp; //각 2*2행렬에서 2번쨰로 큰수 담아놓는 벡터

void func(int cnt){ //cnt: 현재 행(열)의 의 갯수
   
    while(cnt!=1){ //행,열 갯수가 1일때까지 반복
        tmp.clear();
         int x=0; int y=0; //현재 x,y좌표
         int c_index=0; // 다음 행으로 언제 넘어갈지를 조절하는 인덱스
        for(int i=0; i<cnt/2; i++){
            for(int j=0; j<cnt/2; j++){
                vector<int> v; //2*2 행렬에 해당하는 4개의 수를 넣어놓는 임시 벡터
                v.push_back(arr[y][x]);
                v.push_back(arr[y][x+1]);
                v.push_back(arr[y+1][x]);
                v.push_back(arr[y+1][x+1]);

                sort(v.begin(),v.end(),greater<int>());
                tmp.push_back(v[1]); //2번째로 큰수 tmp에 삽입 


                c_index++;
                if(c_index%(cnt/2)==0){  //다음행 살펴보기
                    x=0;
                    y+=2;

                }else{
                    x+=2;
                }
                
            }
        }

        //1차원벡터 tmp로 2차원배열 만들기.
        //다음으로 만들어지는 배열은 (현재 행/2) *(현재 행 열/2) 배열이다.
        int index=0; 
        for(int i=0; i<cnt/2; i++){
            for(int j=0; j<cnt/2; j++){
                arr[i][j]=tmp[index];
                index++;
            }
        }

        //행,열 2배씩 축소
        cnt/=2;
        
    }

    

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    func(n);
    cout<<tmp[0]<<"\n";

}   