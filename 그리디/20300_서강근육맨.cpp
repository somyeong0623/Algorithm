//20300번: 서강 근육맨
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long answer=0;
long long answer1=0;
long long temp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    vector<long long> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());

    if(n%2==0){ //n이 짝수
        for(int i=0; i<n/2; i++){
            temp=v[i]+v[n-1-i];
            if(answer<temp)
                answer=temp;
        }
    }else{ //n이 홀수


        //제일큰수 제외하고 계산
        for(int i=0; i<n/2-1; i++){
            temp=v[i]+v[n-2-i];
            if(answer<temp)
                answer=temp;
        }

        //마지막 운동기구와 최댓값 비교
        if(answer<v[n-1])
            answer=v[n-1];
    }

    cout<<answer<<"\n";

}