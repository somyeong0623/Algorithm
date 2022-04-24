
/*
N: 돌을 던지는 사람의 수 1<=N<=1,000
돌이 떨어지는 위치들 -100,000 이상 100,000 이하 정수

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int TC;
int n;
int min_num;


void func(int n){
    vector<int> v;
    unordered_map<int,int> um;
    min_num=100000;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    for(int i=0; i<v.size(); i++){
        int num=v[i];
        if(num<0){
            num= -num;
        }
        if(num<min_num){
            min_num=num;
        }
            um[num]++;

    }
    cout<<min_num<<" "<<um[min_num]<<"\n";


    
}


int main(){
    cin>>TC;
    for(int i=1; i<=TC; i++){
        cin>>n;
        cout<<"#"<<i<<" ";
        func(n);
    }
}