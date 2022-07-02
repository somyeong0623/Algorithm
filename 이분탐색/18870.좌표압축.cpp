//18870. 좌표 압축
/*
1<=N<=1,000,000
-10^9 <= Xi <= 10^9

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v; //오름차순 정렬할 벡터
vector<int> v2;//좌표압축 진행할 벡터
vector<int> v3; //입력받은 벡터 보관할 벡터

//좌표압축 된 v2에서 이분탐색 시행.
int func(int x){
    int st=0;
    int en=v2.size()-1;
    int mid=0;
    while(st<=en){
        mid=(st+en)/2;
        if(v2[mid]==x){
            return mid;
        }else if(v2[mid]>x){
            en=mid-1;
        }else{
            st=mid+1;
        }
    }

    return 0;
}

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

    //v1내용을 v2로 좌표 압축 (중복 제거)
    sort(v.begin(),v.end());
    int tmp=v[0];
    v2.push_back(v[0]);
    for(int i=1; i<n; i++){
       if(tmp!=v[i]){
            v2.push_back(v[i]);
            tmp=v[i];
       }
    }

    for(int i=0; i<n; i++){
        cout<<func(v3[i])<<" ";
    }
}