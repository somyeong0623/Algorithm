//10816. 숫자 카드 2 (index 직접 구현)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int cnt;

int lower_index(int x, vector<int> &v){ //x가 등장하는 시작 index
    int st=0; 
    int en=n; //n-1 아님 주의
    int mid=0;
    while(st<en){
        mid=(st+en)/2;
        if(v[mid]>=x){
            en=mid;
        }else{
            st=mid+1;
        }
    }
    return st;
}

int upper_index(int x, vector<int> &v){//x 초과인 숫자가 등장하기 시작하는 index
    int st=0;
    int en=n; //n-1 아님 주의
    int mid=0;
    while(st<en){
        mid=(st+en)/2;
        if(v[mid]>x){
            en=mid;
        }else{
            st=mid+1;
        }
    }
    return st;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<int> v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    cin>>m;
    while(m--){
        int x;
        cin>>x;
        cnt=upper_index(x,v)-lower_index(x,v);
        cout<<cnt<<" ";
    }
}