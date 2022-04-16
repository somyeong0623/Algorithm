// 2005번: 파스칼의 삼각형

/*

1<=N<=10
*/
#include <iostream>
using namespace std;


int t;
int n;
int arr[11][11];
int main(){
    cin>>t;
    for(int i=1; i<=t; i++){
        //배열 초기화
        for(int a=0; a<11; a++){
            for(int b=0; b<11; b++){
                arr[a][b]=0;
            }
        }
        cout<<"#"<<i<<"\n";
        cin >>n;

        
        arr[1][1]=1;
        cout<<arr[1][1]<<"\n";
        for(int i=2; i<=n; i++ ){
            for(int j=1; j<=i; j++){
                arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
  


}