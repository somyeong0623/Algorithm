//2847. 게임을 만든 동준이
/*
풀이
앞 레벨의 점수가 뒤 레벨의 점수보다 최소 1은 작아야한다
높은 레벨 인덱스부터 거꾸로 for문을 돌면서
i-1번 레벨의 점수가 i번 레벨의 점수보다 높거나 같으면 낮아질때까지 1씩 빼주면서 빼는 횟수를 세준다.
총 빼준횟수의 합이 정답인 answer이 된다.
*/

#include <iostream>
using namespace std;

int n;
int arr[101];
int answer;

int main(){
    cin>>n;
    for(int i=0; i<n ;i++){
        cin>>arr[i];
    }

    for(int i=n-1; i>0; i--){
        if(arr[i-1]>=arr[i]){ //이전 레벨의 점수가 다음레벨의 점수보다 크거나 같으면
            while(arr[i-1]>=arr[i]){ // 작아질때까지 1씩 빼주고, 몇번 뺏는지 횟수 세주기
                arr[i-1]--;
                answer+=1;
            }
        }
    }
    cout<<answer<<"\n";

}