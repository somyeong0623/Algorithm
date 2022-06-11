//22864. 피로도
/* 
풀이
하루는 24시간이므로 24시간 반복하면서 일을 할수있는지 또는 쉬어야 하는지를 체크한다.
다음 1시간동안 일을해도 피로도가 m이 안넘으면 일을하고, 넘으면 쉰다
이 방식을 반복화여 최종 일한 양을 계산한다.

*/
#include <iostream>
using namespace std;

int a,b,c,m;// 쌓이는 피로도 양, 일처리 양, 피로도 회복 양, 최대 피로도
int answer; //한 일
int pirodo; //피로도

int main(){
    cin>>a>>b>>c>>m;
    int n=24;
    while(n--){


        if(pirodo+a<=m){ 
            answer+=b;
            pirodo+=a;
        }
        else{
            pirodo-=c;
            if(pirodo<0) //피로도가 음수면 0으로 갱신
                pirodo=0;
        }
    }

    cout<<answer<<"\n";

}