//10973번 : 이전순열
#include <iostream>
using namespace std;

//1. 수열에서 어느 인덱스를 기점으로 마지막 수열인지 찾는다 -> i
//2. i-1번째 수를 그 다음수로 바꾼다.
//그 다음수란  i-1번째보다 가장 멀리있으면서 i-1번 수보다 작은 숫자이다. 그수를 j번째수라하자.
//3. i-1번째수와 j번째 수를 바꾼다.
//4. i번째수부터 n-1번째수를 뒤집는다.
//그 이전수열 완성


bool func(int arr[], int n){
    int i=n-1;
    while(i>0 && arr[i]>arr[i-1])
    i--;

    if(i<=0)
    return false;

    int j= n-1;
    while(arr[i-1]<arr[j])
    j--;

    swap(arr[i-1],arr[j]);
    j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    return true;


}


int arr[10001];

int main(){
    int n; 
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(func(arr,n)){
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
    }else{
        cout<<-1<<"\n";
    }
    
}