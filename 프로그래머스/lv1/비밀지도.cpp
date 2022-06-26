#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> mix;
    
    //두 지도 합치기
    for(int i=0; i<n; i++){
        int x=arr1[i]|arr2[i]; //or연산 
        mix.push_back(x);
    }
    
    for(int i=0; i<n; i++){
        string tmp="";
        int cur=mix[i];
        for(int j=n-1; j>=0; j--){ //2진수 맨앞자리부터 0인지 1인지 확인
            if(cur>=pow(2,j)){ 
                tmp+="#";
                cur-=pow(2,j);
            }else{
                tmp+=" ";
            }  
        }
        answer.push_back(tmp);
    }
    return answer;
}