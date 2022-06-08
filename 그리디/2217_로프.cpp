//2217. 로프
/*
풀이
'모든 로프를 다 사용해야할 필요는 없다' 라는 말이 중요하다.
만약 n개의 로프를 사용할것이라고 하면, 
들어올릴 수 있는 최대 중량은n개의 로프중 가장 작은 중량 * n개 이다.
입력받은 벡터를 정렬 한 후, 포문을 돌면서 작은값부터 하나씩 제외하면서 제외했을때의 최대 중량과 포함했을때의 최대 중량 중 큰값을 구하면 된다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int answer;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    answer=v[0]*n;
    for(int i=1; i<n; i++){
        if(answer<v[i]*(n-i))
            answer=v[i]*(n-i);
    }

    cout<<answer<<"\n";
    

}