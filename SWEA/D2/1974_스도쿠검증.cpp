#include <iostream>
#include <string.h>
using namespace std;

int TC;
int arr[10][10];
 bool check[10];
bool func(){

    //1. 행 전부체크
    for(int i=1; i<=9; i++){
       memset(check,false,sizeof(check));

        for(int j=1; j<=9; j++){
            if(check[arr[i][j]]==false){
            check[arr[i][j]]=true;
            }else{
                // cout<<"행 체크 오류"<<"\n";
                // cout<<i<<" "<<j<<endl;
                return false;
            }

        }
    }

    //2. 열 전부체크
    for(int j=1; j<=9; j++){
       memset(check,false,sizeof(check));

        for(int i=1; i<=9; i++){
            if(check[arr[i][j]]==false){
            check[arr[i][j]]=true;
            }else{
                // cout<<"열 체크 오류"<<"\n";
                // cout<<i<<" "<<j<<endl;
                return false;
            }

        }
    }
    //3. 3*3 작은 격자 체크
    for(int i=1; i<=9; i+=3){
       for(int j=1; j<=9; j+=3){
           memset(check,false,sizeof(check));
           for(int x=i; x<i+3; x++){
               for(int y=j; y<j+3; y++){
                //    cout<<"x: "<<x<<", y: "<<y<<"\n";

                    if(check[arr[x][y]]==false){ //아직 사용 안했으면
                    check[arr[x][y]]=true;
                    }else{ //이미 사용한 숫자면 스도쿠 실패므로 false리턴
                        return false;
            }
               }
           }


       }
    }

    return true;
}


int main(){
    cin>>TC;
    for(int i=1; i<=TC; i++){
        for(int j=1; j<=9; j++){
            for(int k=1; k<=9; k++){
                cin>>arr[j][k];
            }
        }
        cout<<"#"<<i<<" "<<func()<<"\n";


    }
}