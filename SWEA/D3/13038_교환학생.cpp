//13038번: 교환학생
/*

풀이
먼저 생각한 방법은 입력받은 배열을 계속 돌면서 cnt가 n이 될때까지 반복하는 것이다
이러면 시간초과일것 같다.

두번째는 몫과 나머지 이용


*/


#include <iostream>
using namespace std;

int TC;
int arr[100000];
int cnt;
int cur;
int answer;

int main(){

    cin>>TC;
    for(int t=1; t<=TC; t++){
        cout<<"#"<<t<<" ";
        int n;
        cnt=0;

        cin>>n;

        for(int i=0; i<7; i++){
            cin>>arr[i];
        }
        for(int i=0; i<7; i++){
            cout<<arr[i]<<" ";
        }

        cur=0;
        answer=0;
        while(true){
            cout<<"answer: "<<answer<<"\n";
            if(cur==n)
                cur=0;

            if(arr[cur]==1)
                cnt++;

            if(cnt==n){
                cout<<"cur: "<<cur<<endl;
                break;
            }
            
            cur++;
            answer++;
            
        }

        cout<<answer<<"\n";
    }
}