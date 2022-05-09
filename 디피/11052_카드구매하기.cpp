//11052번: 카드 구매하기

/*

풀이
d[n]: 카드 N개를 사는데 지불하는 금액의 최댓값
p[n]: 카드가 n개 들어있는 카드팩의 가격

예를 들어 n=4일때, d[4]는 아래 네가지 경우 중의 최댓값이다.
1) d[0]+p[4]
2) d[1]+p[3]
3) d[2]+p[2]
4) d[3]+p[1]
이와 같은 방법으로 d[n]을 구해주면 된다.

d[n]을 구하는 시간복잡도는 내부 포문만큼이므로 O(n)이고,
n의 범위는 1~n 이므로 총 시간복잡도는 O(n^2)가 된다.

*/
#include <iostream>
#include <cmath>
using namespace std;

int p[1001];
int d[1001];

int main(){
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>p[i];
    }

    d[0]=0;
    d[1]=p[1];

    for(int i=2; i<=n; i++){
        for(int j=0; j<=i-1; j++){
            int temp=d[j]+p[i-j];
            if(d[i]<temp){
                d[i]=temp;
            }
        }
    }


    cout<<d[n]<<"\n";
}