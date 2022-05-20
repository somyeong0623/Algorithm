//12741번: 두 전구 (왜 틀리지? 모르겠음 )
#include <iostream>
using namespace std;

int TC;
int answer;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>TC;
    for(int t=1; t<=TC; t++){
        cout<<"#"<<t<<" ";


        int a,b,c,d;
        cin>>a>>b>>c>>d;

        // if(b<c){
        //     answer=0;
        // }
        // else{
        //     if(b>=d){
        //         answer=d-c;
        //     }else{ //b<d
        //         answer=b-c;
        //     }
        // }

        if(b<=c)
            answer=0;
        else
            answer=min(b,d)-max(a,c);

        cout<<answer<<"\n";
    }
}
