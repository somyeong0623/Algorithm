//18870. 좌표 압축 (STL 이용)
/*
1<=N<=1,000,000
-10^9 <= Xi <= 10^9

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v; //오름차순 정렬하고, 중복 제거할 벡터
vector<int> v3; //원래 벡터

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
        v3.push_back(x);
    }


    sort(v.begin(),v.end());
    //unique 함수 이용하여 중복 제거
    //unique: 중복이 제거된 원소들은 제거되고, 앞쪽에 모아준다.
    // 남은 뒤쪽자리에는 쓰레기값이 들어가고, 쓰레기값이 시작되는 구간을 리턴해준다.
    // erase를 이용해 쓰레기값들 없애기.
    v.erase(unique(v.begin(),v.end()),v.end());

    for(int i=0; i<n; i++){
        cout<<lower_bound(v.begin(),v.end(),v3[i])-v.begin()<<" ";
    }
}