//2170. 선 긋기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector <pair<int,int>> v;
long long answer;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0; i<n; i++){
        int left, right;
        cin>>left>>right;
        v.push_back({left,right});
    }
    sort(v.begin(), v.end());//오름차순 정렬
    
    int l=v[0].first; //선의 왼쪽지점
    int r=v[0].second; //선의 오른쪽 지점
    answer=r-l;
    for(int i=1; i<n; i++){
        if(v[i].first>r){ //겹치지 않는 경우
            l=v[i].first; //왼쪽지점 갱신
            r=v[i].second; //오른쪽지점 갱신
            answer+=(r-l);
            // cout<<"answer: "<<answer<<"\n";

        }else if(v[i].first<=r && v[i].second>r){  //겹치는 경우(딱 붙는경우도 포함)
            answer+=(v[i].second-r);
            l=v[i].first; //왼쪽지점 갱신
            r=v[i].second;// 오른쪽지점 갱신
            // cout<<"answer: "<<answer<<"\n";
            
        }
    }
    cout<<answer<<"\n";

}