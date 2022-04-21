/*
3<=N<=7
*/

#include <iostream>
#include <string.h>
using namespace std;
int TC,n;
int arr[8][8];
int arr1[8][8];
int arr2[8][8];
int arr3[8][8];


int main(){
    cin>>TC;
    for(int t=1; t<=TC; t++){
        cin>>n;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin>>arr[i][j];
            }
        }

        //90도 회전
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                arr1[j][n-i+1]=arr[i][j];
            }
        }

          //180도 회전
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                arr2[j][n-i+1]=arr1[i][j];
            }   
        }
    

          //270도 회전
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                arr3[j][n-i+1]=arr2[i][j];
            }
        }


        //출력
        cout<<"#"<<t<<"\n";

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cout<<arr1[i][j];
            }
            cout<<" ";

             for(int j=1; j<=n; j++){
                cout<<arr2[i][j];
            }
            cout<<" ";

             for(int j=1; j<=n; j++){
                cout<<arr3[i][j];
            }
            cout<<"\n";

        }
    }
}