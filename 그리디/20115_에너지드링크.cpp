//20115. 에너지 드링크
/*
가장 양이 많은 드링크에 나머지것을 합치는것이 양을 최대로 하는 방법이다.
왜냐하면 양을 최대로 하려면 버리는 음료의 양이 최소가 되어야 하는데, 
결국에는 합친음료의 반을 버리는 것보다는, 합치기전의 음료의 반을 버리는것이 최소로 버리는 것이므로
제일 양이 많은 음료를 제외한 나머지 음료를 반씩 버리는것이 최선의 방법이다.

- 벡터를 오름차순 정렬후, 가장 큰 값 v[0]으로 answer를 초기화 한다.
- for문을 돌면서 1번째 부터 n-1번째 음료를 반 버린값을 answer에 더한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    vector<double> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end(), greater<int>());//오름차순 정렬
    double answer=v[0]; //가장 양이 많은 음료의 양으로 초기화
    for(int i=1; i<n; i++){
        answer+=v[i]/2;// 1번부터 n-1번째 까지의 음료를 반 버리고 더하기.
    }
 
    cout<<answer<<"\n";
}
