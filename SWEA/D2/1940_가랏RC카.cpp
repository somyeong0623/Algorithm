#include <iostream>
using namespace std;

int TC;
int n;
int answer; //이동한 거리
int v; //속도

int main(){
    cin>>TC;
    for(int t=1; t<=TC; t++){
        cin>>n;
        answer=0; // 이동한 거리
        v=0; //속도

        for(int i=0; i<n; i++){
            int x;
            cin>>x;
           if(x==0){ //속도 유지
               answer+=v; 

           }else if(x==1){ //가속한 경우
               int y;
               cin>>y;
               v+=y;
               answer+=v;
           }else{ //감속한 경우
                int y;
                cin>>y;
                if(v<y){//현재속도가 감속할 속도보다 큰 경우, 속도는 0이 된다.
                    v=0;
                    
                }else{

                v-=y;
                answer+=v;
                }
           }
        }
        //출력
        cout<<"#"<<t<<" "<<answer<<"\n";
    }

}