//1920. 수 찾기(STL사용)
/*
<algorithm> 헤더에 있는 binary_search 사용
범위는 오름차순으로 정렬되어 잇어야함.
그렇지 않으면 실제로는 값이 들어있는데 들어있지 않다고 판단할 수도 있음.
binary_search(범위의 시작, 범위의 끝, 타켓)

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n,m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    vector<int> v(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());
    

    cin>>m;
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        //범위 내에서 원소가 존재하면 true, 아니면 0 리턴
        cout<<binary_search(v.begin(),v.end(),x)<<"\n";
    }


}