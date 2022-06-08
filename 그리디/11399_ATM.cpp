//11399. ATM
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int arr[1001];
int answer;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end()); //오름차순 정렬

    //arr[i]: i번째 사람이 돈을 인출하는데 총 걸리는 시간(기다리는시간 + 걸리는 시간)
    arr[0]=v[0]; 
    for(int i=1; i<n; i++){
        arr[i]=arr[i-1]+v[i]; 
    }

    //answer: 걸리는 시간들의 합
    for(int i=0; i<n; i++){
        answer+=arr[i];
    }

    cout<<answer<<"\n";
}