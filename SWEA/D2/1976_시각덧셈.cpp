#include <iostream>
using namespace std;

int TC;
int h1, m1, h2, m2;
int hour, minute;

int main(){
    cin>>TC;
    for(int i=1; i<=TC; i++){
        cin>>h1>>m1>>h2>>m2;
        hour=h1+h2;
        if(hour>12){
        hour=(h1+h2)%12;
        }

        minute=m1+m2;
        if(minute==60){
            minute=0;
            hour++;
        }else if(minute>60){
            minute=minute%60;
            hour++;
        }
        
        cout<<"#"<<i<<" "<<hour<<" "<<minute<<"\n";

    }
}