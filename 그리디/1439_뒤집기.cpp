//1439. 뒤집기
/*풀이
한번 뒤집을때, 연속된 숫자를 모두 뒤집어야 한다.
0이 연속된 부분의 갯수와 1이 연속된 부분의 갯수 중 작은 쪽이 최소 횟수가 된다.

*/
#include <iostream>
#include <string>
using namespace std;

int cnt_one;
int cnt_zero;
int answer;

int main(){
    string s;
    cin>>s;

    char prev='2'; //초기 문자: 0과 1이 아닌 숫자 아무거나
    for(int i=0; i<s.size(); i++){
            if(s[i]!=prev){ //이전 문자와 다르면 연속된 부분 갯수 카운트하기
                if(s[i]=='0'){
                    cnt_zero++; //0이 연속된 부분의 갯수
                    prev='0'; //이전 문자 갱신
                }
                else{
                    cnt_one++; //1이 연속된 부분의 갯수
                    prev='1';  //이전 문자 갱신
                }
            }
    }

    if(cnt_one<cnt_zero)
        answer=cnt_one;
    else
        answer=cnt_zero;

    // cout<<cnt_zero<<" "<<cnt_one<<"\n";
    cout<<answer<<"\n";

}