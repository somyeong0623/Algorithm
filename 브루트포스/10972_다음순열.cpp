//10972번 : 다음 순열
#include <iostream>
using namespace std;

int n;
int arr[100001];
bool check[10001];

//1. 주어진 수열이 어떤 수를 기점으로 마지막 순열인지 찾는다.-> i번째 인덱스
//이때 0번째인덱스 까지 i가 발견되지 않으면 마지막 수이므로 -1를 리턴한다.
//2. i-1번째 수를 그 다음수로 바꿔 주어야 한다.
// 그 다음수란 인덱스가 가장 크면서 i-1번째 수보다 큰 수이다. 물론 i-1번째 수보다 오른쪽에있는수 한정이다.
//3. 그 수의 index를 j라고 하면 i-1번째수와 j번째 수를 바꾼다.
//4. i-1번과 j번 사이의 수는 내림차순 상태이므므로 수열을 뒤집어서 내림차순으로 변경한다.
// 완성된 수가 다음에 오는 순열이다.


bool func(int arr[], int n){
    //1.번 과정
    int i=n-1; 
    while (i>0 && arr[i-1]>=arr[i])
    i--;
    // cout<<"i= "<<i<<"\n";

    if(i<=0)
    return false;

    //2번 과정
    int j=n-1;
    while(arr[j]<=arr[i-1])
    j--;

    //3번 과정
    swap(arr[i-1],arr[j]);

    j=n-1;
    //4번 과정
    while(i<j){
        swap(arr[i],arr[j]);
        i+=1;
        j-=1;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(func(arr,n)){
        for(int i=0; i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
    else{
        cout<<-1<<"\n";
    }
}   