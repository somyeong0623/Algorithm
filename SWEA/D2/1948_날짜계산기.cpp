/*
[제약 사항]

월은 1 이상 12 이하의 정수이다. 각 달의 마지막 날짜는 다음과 같다.

1/31, 2/28, 3/31, 4/30, 5/31, 6/30, 7/31, 8/31, 9/30, 10/31, 11/30, 12/31

두 번째 날짜가 첫 번째 날짜보다 항상 크게 주어진다.
*/
#include <iostream>
using namespace std;
int TC;
int m1,d1,m2,d2;
int sum;

int main(){
    cin>>TC;
    for(int t=1; t<=TC; t++){
        sum=0;
        cin>>m1>>d1>>m2>>d2;
        for(int i=m1; i<m2; i++){
            //31일 까지있는 월 이면
            if( i==1|| i==3 || i==5 || i==7 || i==8 || i==10 || i==12 ){
                sum+=31;
            }else if(i==2){ //28일 까지인 월 이면
                sum+=28;
            }else{ //30일 까지 있는 월 이면
                sum+=30;
            }
        }

        sum= sum-d1+d2+1;
        
         cout<<"#"<<t<<" "<<sum<<"\n";
    }
   

}