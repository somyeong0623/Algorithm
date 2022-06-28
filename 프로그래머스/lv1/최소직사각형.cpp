//lv1. 최소직사각형

/*
풀이
각 명함의 가로,세로중 큰것을 big벡터에 작은것을 small벡터에 넣기
big,small벡터에서 가장큰값 두개 곱한것이 answer.
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> big;
vector<int> small;

int solution(vector<vector<int>> v) {
    int answer = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i][0]>=v[i][1]){
            big.push_back(v[i][0]);
            small.push_back(v[i][1]);
        }else{
            big.push_back(v[i][1]);
            small.push_back(v[i][0]);
        }
    }
    sort(big.begin(),big.end(),greater<int>()); //내림차순 정렬
    sort(small.begin(),small.end(),greater<int>());
    answer=big[0]*small[0];
    return answer;
}