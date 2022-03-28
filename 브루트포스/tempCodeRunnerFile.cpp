//110971번: 외판원 순회2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[11][11];
int answer=2100000000;

int func(int arr[][11], vector<int> v, int n){
    int result=0;
 
   
    for(int i=0; i<n-1; i++){
         if(arr[v[i]-1][v[i+1]-1]==0){ //길이 없는 경우
            return 0;
         }
        
        //i에서 i+1로 갈수있는 경우에만 진행
            result+=arr[v[i]-1][v[i+1]-1];
        
    }
    //수열은 1,2,3,4 자연수고 인덱스는 0부터 시작하므로 1 빼줘야함.
    //마지막에, 처음 지점으로 돌아오는 비용 더해야함

    // n-1번째랑 0번째 길이 없는경우도 체크 해야함!
    if(arr[v[n-1]-1][v[0]-1]==0)
    return 0;
    else{
    result+=arr[v[n-1]-1][v[0]-1];
    }

   
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        v[i]=i+1;
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }


    do{
        int result=func(arr,v,n);
        //  cout<<result<<"\n";
        if(answer>result)
        answer=result;

    }while(next_permutation(v.begin(),v.end()));

    cout<<answer<<"\n";
    

}