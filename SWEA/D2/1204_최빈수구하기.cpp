/*
[제약 사항]

학생의 수는 1000명이며, 각 학생의 점수는 0점 이상 100점 이하의 값이다.
 
[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 줄에는 테스트 케이스의 번호가 주어지고 그 다음 줄부터는 점수가 주어진다.

[출력]

#부호와 함께 테스트 케이스의 번호를 출력하고, 공백 문자 후 테스트 케이스에 대한 답을 출력한다.
*/
#include <iostream>
#include <string.h>

using namespace std;
int TC;
int arr[1001];
int max_num;
int answer;

int main(){
    cin>>TC;
    for(int i=1; i<=TC; i++){
        int t;
        cin>>t;
        
        memset(arr,0,sizeof(arr));
        max_num=0;
        for(int j=0; j<1000; j++){
            int x;
            cin>>x;
            arr[x]++;
        }

        for(int j=0; j<100; j++){
            if(arr[j]>=max_num){ //주의할점: 최빈수가 여러개일때는 가장 큰 점수를 출력해야 하므로 >가 아니라 >=를 통해 더 큰것으로 갱신되도록 해야한다!!!
                max_num=arr[j];
                answer=j;
            }
        }
        cout<<"#"<<t<<" "<<answer<<"\n";


    }

}