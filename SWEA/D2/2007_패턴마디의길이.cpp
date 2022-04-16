/*
각 문자열 길이 : 30
마디의 최대길이 10

*/

// 마디의 최대길이가 10이니까, 마디의 길이가 1~10까지 전부 해보는 방식
// 예를들어 마디의 길이가 2라면, 0~1번째 문자, 2~3,,,, 8~9번째 문자 같은지 확인. 같으면 break;
#include <iostream>
#include <string>
using namespace std;

int t;
int answer;

// 작은 사이즈가 최선!
void func(string s){
    bool flag=true;
    answer=0;

    for(int size=2; size<=10; size++){

        if(s.substr(0,size)!=s.substr(size,size)){
            continue;
        }else{ //같으면
            answer=size;
            break;
        }

    }

}

int main(){
    cin>>t;
    
    for(int i=1; i<=t; i++){
        string s;
        cin>>s;
        func(s);
        cout<<"#"<<i<<" "<<answer<<"\n";


    }
}