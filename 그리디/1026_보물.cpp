//1026. 보물
/*
풀이
수열 a와 b의 각쌍의 합중 최솟값을 구하는 문제이다.
이때 a는 재배열이 가능하고, b는 재배열이 불가능하다.
최솟값을 구하려면 a의 작은값과 b의 큰값을 곱해주는 형태로 계산하면 된다.
b는 재배열이 불가능하지만, a는 재배열이 가능해서 원하는 쌍을 맺어줄수 있기때문에 결국에는 b를 재배열못하는것이 의미가 없다.!
a는 오름차순, b는 내림차순으로 정렬하여 각 쌍의 합을 구하면 최솟값이다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int answer;

int main(){
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        cin>>b[i];
    }

    sort(a.begin(), a.end()); //a 오름차순 정렬
    sort(b.begin(),b.end(),greater<int>()); //b 내림차순 정렬

    for(int i=0; i<n; i++){
        answer+=a[i]*b[i];
    }

    cout<<answer<<"\n";
}