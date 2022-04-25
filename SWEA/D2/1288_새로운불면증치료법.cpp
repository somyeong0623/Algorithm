/*
[입력]

첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 N (1 ≤ N ≤ 106)이 주어진다.

[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

최소 몇 번 양을 세었을 때 이전에 봤던 숫자들의 자릿수에서 0에서 9까지의 모든 숫자를 보게 되는지 출력한다.

( 민석이는 xN번 양을 세고 있다. )
*/
#include <iostream>
#include <string.h>
using namespace std;

int TC, n;
bool check[10];
int num;
bool flag;

int func(int n){
    memset(check,false,sizeof(check));
    num = 0;

    while(true){
        num+=n; //num은 n부터 시작

        string s= to_string(num); //num을 string으로 변경해서 string을 돌면서 숫자 사용여부 체크

        for(int i=0; i<s.size(); i++){ //string 사이즈 만큼 실행
            int x=s[i]-'0'; // char형을 int형으로 바꾸는 방법
            if(check[x]==false){// 해당 숫자를 사용하지 않았을 경우만 true로 변경해줌
                check[x]=true;
            }
        }
        // 한번의 연산(num+=n)이 끝났을 때마다 0~9숫자를 전부 사용하였는지 여부를 체크하고
        // 전부 사용한게 확인된다면 그때의 num을 return

        for(int i=0; i<=9; i++){
            flag=true; // 이 줄을 어디에 작성해야할지 헷갈렸는데, 체크하는 for문 시작지점에 선언해야함
                       // 각 num을 반영할때마다 check가 전부 true인지 확인해야 하므로 for문 처음에 flag=true 초기화가 필요하다.
            if(check[i]==false){ //하나라도 사용안한 숫자가 있으면 flag를 false로 변경하고 break;
                flag=false;
                break; 
            }
        }
        if(flag==true){ //check배열을 전부 확인한후, flag가 true이면 num 리턴
            return num;
        }
  
    }
}

int main(){

    cin>>TC;

    for(int i=1; i<=TC; i++){
        cin>>n;
        cout<<"#"<<i<<" "<<func(n)<<"\n";
    }
}