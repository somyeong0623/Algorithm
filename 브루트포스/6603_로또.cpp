 //6603번: 로또
#include<iostream>
#include <vector>
#include <memory.h>
#include <algorithm>

using namespace std;
int arr[6];
bool check[50];

//테스트케이스 문제이므로, 각 테스트 마다 vector v와 n값 달라서 넣어줘야함
// index와 start는 재귀를 돌 때, 달라지는 값
void func(vector<int> &v,int n,int index,int start){
  
    if(index==6){
  
        for(int i=0; i<6; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    //사전순 출력이니까 start값 체크.
    for(int i=start; i<n; i++){
        if(check[v[i]])
        continue;

        check[v[i]]=true;
        arr[index]=v[i];
        func(v,n,index+1,i+1);
        check[v[i]]=false;
    }

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        int k;
        cin>>k;

        if(k==0)
        break;

        vector <int> v(k);

        for(int i=0; i<k; i++){
          cin>>v[i];
        }

        //배열 arr 0으로 초기화
        //bool check배열도 false로 초기화
        // sort(v.begin(), v.end());  //오름차순으로 주어져서 안해도됨.
        memset(arr,0,sizeof(arr));
        memset(check,0,sizeof(check));
     
        func(v,k,0,0);
          
        cout<<"\n";

    }
}
// 브루트포스에서 가장 중요한것은 재귀