//11053. 가장 긴 증가하는 부분 수열
/*
수열의 크기 1<=N<=1,000
원소 1<=Ai<=1,000

*/

#include <iostream>
using namespace std;

int arr[1001];
int cnt[1001]; //처음부터 현재인덱스까지 봤을때 가장 긴증가하는 부분수열의 길이
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i]; 
        cnt[i]=1;

    }

    //max : 현재 인덱스보다 앞에 있는 수 중 원소값은 arr[cur]보다 작으면서 cnt값은 가장 큰 원소의 cnt 값
    for(int i=0; i<n; i++){
        int cur=i;//현재 cnt[cur]을 구하려는 인덱스 cur
        int max=0; // max : 현재 인덱스보다 앞에 있는 수 중 원소값은 arr[cur]보다 작으면서 cnt값은 가장 큰 원소의 cnt 값.  인덱스 바뀔때마다 0으로 초기화
        for(int j=0; j<i; j++){
            if(arr[j]<arr[cur]){ 
                if(cnt[j]>max){  // 만족하는 수중 가장 큰 cnt값 찾기
                    max=cnt[j];
                    cnt[cur]=max+1;
                }
            }
        }
    }

    int answer=0;
    for(int i=0; i<n; i++){
        if(answer<cnt[i]){
            answer=cnt[i];
        }
    }

    cout<<answer<<"\n";

}