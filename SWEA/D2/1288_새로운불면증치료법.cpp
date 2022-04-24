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
        num+=n;

        string s= to_string(num);

        for(int i=0; i<s.size(); i++){
            int x=s[i]-'0'; 
            if(check[x]==false){
                check[x]=true;
            }
        }

        for(int i=0; i<=9; i++){
            flag=true;
            if(check[i]==false){
                flag=false;
                break;
            }
        }
        if(flag==true){
            return num;
        }
        num+=n;      
    }
}

int main(){

    cin>>TC;

    for(int i=1; i<=TC; i++){
        cin>>n;
        cout<<"#"<<i<<" "<<func(n)<<"\n";
    }
}