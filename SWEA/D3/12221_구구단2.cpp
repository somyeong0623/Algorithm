//12221번: 구구단
#include <iostream>
using namespace std;

int TC;
int answer;

int main(){
    cin>>TC;
    for(int t=1; t<=TC; t++){
        cout<<"#"<<t<<" ";

        int x,y;
        cin>>x>>y;

        if(x>=10 || y>=10)
            answer=-1;
        else  
            answer=x*y;

        cout<<answer<<"\n";
    }
}