/*풀이
d[i]:0번부터 i번째 집까지 고려했을때, 도둑이 훔칠수 있는 돈의 최댓값

두 경우로 나눠서 둘중에 최댓값을 구해야 한다. 
동그랗게 배치된 집들의 돈을  배열 money[]라고 했을때 (인덱스는 0부터 시작)
1) 0번째 집이 포함되고, 마지막 집이 제외된 경우
2) 0번째 집이 제외되고, 마지막 집이 포함된 경우

d[i]의 점화식
d[0], d[1]은 초기화 해주어야 한다.
d[i]=max(d[i-1], d[i-2]+money[i]

1번 경우의 결과를 배열 d[]라고 하고, 2번 경우의 결과를 배열 p[]라고 할때, (집의 갯수 = n)
d의 최댓값은 d[n-2]에 담기고, p의 최댓값은 p[n-1]에 담기므로, 둘중 최댓값이 답이된다.


*/
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int d[1000001];
int p[1000001];


int solution(vector<int> money) {
    int answer = 0;
    
    //처음집 포함. 마지막집 제외
    d[0]=money[0];
    d[1]=max(d[0], money[1]); //여기 주의!!!!
    //처음에 d[1]=money[1]이라고해서 테케1번 틀림.
    //d[i]정의는 0~i번째 집까지 고려했을때의 최댓값이니까 d[0]과 money[1]중에 큰값이 d[1]이 되어야한다.
    
    for(int i=2; i<money.size()-1; i++){
        d[i]=max(d[i-1],d[i-2]+money[i]);
    }
    
    //처음집 제외, 마지막집 포함
    p[0]=0;
    p[1]=money[1];

    for(int i=2; i<money.size(); i++){
        p[i]=max(p[i-1],p[i-2]+money[i]);
    }
    
    //최댓값 구하기
    int n=money.size();
    if(d[n-2]>p[n-1])
        answer=d[n-2];
    else
        answer=p[n-1];

    
    
    return answer;
}