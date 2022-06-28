//lv1. 2016년
#include <string>
#include <vector>
#include <iostream>

using namespace std;
int month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};//각 월의 일수 배열
string day[]={"FRI","SAT","SUN","MON","TUE","WED","THU"}; //금요일부터

string solution(int a, int b) { //월,일
    string answer = "";
    int sum=0;
    //1월1일부터~a월b일까지 총 일수 구하기
    for(int i=1; i<a; i++){
        sum+=month[i];
    }
    sum+=b;
    sum-=1; //1월 1일부터시작했으니까 1 빼기
    sum%=7;
    
    
    // cout<<"sum: "<<sum<<"\n";
    answer=day[sum];
    return answer;
}