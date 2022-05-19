//13218번: 조별과제
/*
풀이
입력받은 값을 3으로 나눈 몫을 구하면 된다.
*/

#include <iostream>
using namespace std;

int TC;

int main(){
    cin>>TC;
    for(int t=1; t<=TC; t++){
        cout<<"#"<<t<<" ";

        int x;
        cin>>x;
        cout<<x/3<<"\n";
    }
}