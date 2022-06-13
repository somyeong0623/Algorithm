//2470. 두 용액
/*
용액의수 N 2<=N<=100,000
용액 특성값: -1,000,000,000 이상 1,000,000,000 이하

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 2000000000
using namespace std;

int n;
int st,en;
int sum; //두 용액값의 합
int min_sum=INF;  //두 용액값의 합의 최솟값 저장
int answer1, answer2; //정답 변수
vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){ //입력받아서 벡터에 push
        int x;
        cin>>x;
        v.push_back(x);
    }
    

    sort(v.begin(),v.end());// 오름차순 정렬

    st=0; //처음 원소
    en=n-1; //마지막 원소
    while(st<en){ // <= 아님 주의!
        sum=v[st]+v[en];

        if(abs(sum)<min_sum){// 절대값이 최소면 diff, answer1,2 갱신
            min_sum=abs(sum);
            answer1=v[st];
            answer2=v[en];
        }


        if(sum==0){ //반복문 끝내고 정답 출력하기
            break;
        }
        if(sum<0){
            st++; //sum 증가시키는 방향으로
        }else{ //sum이 양수면
            en--; //sum 감소시키는 방향으로
        }

       
    }

    cout<<answer1<<" "<<answer2<<"\n";

}