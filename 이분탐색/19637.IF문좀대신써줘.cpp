//19637. if문좀 대신 써줘
/*
칭호의 갯수 1<=N<=100,000
캐릭터 갯수 1<=M<=100,000
칭호이름 길이: 1이상 11이하의 영어 대문자
전투력 상한값: 1,000,000,000 이하인 음이 아닌 정수
칭호: 전투력 상한값의 비내림차순으로 주어짐.


*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n,m;
vector<string> name;
vector<int> power;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        string s;
        int x;
        cin>>s>>x;
        name.push_back(s);
        power.push_back(x);

    }
    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        int index=lower_bound(power.begin(),power.end(),x)-power.begin();//power값의 상한 인덱스
        cout<<name[index]<<"\n"; //index에 해당되는 칭호 출력

    }

}