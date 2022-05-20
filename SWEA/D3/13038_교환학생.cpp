//13038번: 교환학생
/*

풀이
먼저 생각한 방법은 입력받은 배열을 계속 돌면서 cnt가 n이 될때까지 반복하는 것이다
이때, 시작하는 날짜는 일요일부터 하는게 아니라 처음 수업이있는 날짜가 카운트를 시작하는 날짜이다.
시간초과는 아닐려나 ..


*/


#include <iostream>
using namespace std;

int TC;
int n;
int arr[100000];
int cnt;
int min_answer=987654321;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>TC;
    for(int t=1; t<=TC; t++){
        cout<<"#"<<t<<" ";

        cin>>n;
        for(int i=0; i<7; i++){
            cin>>arr[i];
        }

        int days=0;
        for(int i=0; i<7; i++){
            if(arr[i]==1)
                days++;
        }

        //시작하는 요일 찾기.
        //일주일중 1인 요일을 전부 시작지점으로 해서 돌려보고 최솟값을 찾는다.
        for(int i=0; i<7; i++){
            if(arr[i]==1){
                int result=count(i);
                if(result<min_answer){
                    min_answer=result;
                }
            }
        }



        cout<<min_answer<<"\n";
    }
}