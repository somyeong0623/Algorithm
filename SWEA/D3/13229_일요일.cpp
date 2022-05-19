//13229번: 일요일
#include <iostream>
using namespace std;

int TC;

int main(){
    cin>>TC;
    for(int t=1; t<=TC; t++){
        cout<<"#"<<t<<" ";

        string s;
        cin>>s;

        if(s=="MON")
            cout<<6<<"\n";
        if(s=="TUE")
            cout<<5<<"\n";
        if(s=="WED")
            cout<<4<<"\n";
        if(s=="THU")
            cout<<3<<"\n";
        if(s=="FRI")
            cout<<2<<"\n";
        if(s=="SAT")
            cout<<1<<"\n";
        if(s=="SUN")
            cout<<7<<"\n";

    
    }
}