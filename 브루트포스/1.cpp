//110971번: 외판원 순회2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[11][11];
int answer;

int func(int arr[][11], vector<int> v, int n){
    int result=0;
    for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    for(int i=0; i<n-1; i++){
        if(arr[v[i]][v[i+1]]){ //i에서 i+1로 갈수있는 경우에만 진행
            result+=arr[v[i]][v[i+1]];
            cout<<"i = "<<i <<"\n";
        }
    }
    //마지막에, 처음 지점으로 돌아오는 비용 더해야함
    result+=arr[v[n-1]][v[0]];
    cout<<"result = "<<result <<'\n';
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
     for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    do{
        int result=func(arr,v,n);
        if(answer>result)
        answer=result;

    }while(next_permutation(v.begin(),v.end()));

    cout<<answer<<"\n";
    

}