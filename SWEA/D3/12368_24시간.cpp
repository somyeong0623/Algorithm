//12368번: 24시간

#include <iostream>
using namespace std;

int TC;
int answer;

int main(){
    cin>>TC;
    for(int t=1; t<=TC; t++){
        cout<<"#"<<t<<" ";

        int a,b;

        cin>>a>>b;
        answer=(a+b)%24;
        cout<<answer<<"\n";

    }

}