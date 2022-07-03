//2295. 세수의 합
/*
U는 집합, 두 수가 같지 않음.
U의 원소: 200,000,000보다 작거나 같은 자연수
x번째수 + y번째수 + z번째수 = k번째 수
x,y,z,k가 서로 같아도 됨.
k번째 수 출력


*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
vector<int> v2;
// bool check[1000001]; //중복체크 -> 이 배열 썼더니 런타임에러(OutOfBound)났음. 
int answer;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());
    //v2[]는 v[]의 두원소의 합의 집합
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int tmp=v[i]+v[j];
            v2.push_back(tmp);
        }
    }

    sort(v2.begin(), v2.end()); //v2오름차순 정렬
    int v_size=v.size();
    int v2_size=v2.size();

    // v[i]+v[j]+v[k]=v[l] 만족하는 최대 v[l]값 찾기
    //v2[m]+v[k]=v[l]
    //v2[m]=v[l]-v[k] 만족하는 m을 벡터 v2를 이분탐색하여 찾기
    //O(N^4)->O(N^2*2logN) 으로 줄일 수 있음
    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            int l=v[i]; //가장 큰값부터
            int k=v[j];
            int target=l-k;
            // cout<<"l: "<<l <<", k: "<<k<<", target: "<<target<<"\n";
            if(binary_search(v2.begin(),v2.end(),target)){
                if(answer<l){
                    answer=l;
                }
            }
        }
    }
    cout<<answer<<"\n";

}