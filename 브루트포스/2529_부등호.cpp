//2529번: 부등호
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;
char arr[10]; //부등호 배열
bool check[10]; //숫자 중복 체크
vector<string> answer;
//가능한 숫자조합 담아놓는 벡터

bool ok(string num){
    for(int i=0; i<k; i++){
        if(arr[i]=='<'){
            if(num[i]>num[i+1]) 
            return false;
        }
        else if(arr[i]=='>'){
            if(num[i]<num[i+1])
            return false;
        }
    }
    return true;
}

void func(int index, string num){ //부등호k개면, 숫자는k+1개
    if(index==k+1){
        if(ok(num)){
            // cout<<"ok num: "<<num<<"\n";
            answer.push_back(num);
        }
        return;
    }
    for(int i=0; i<=9; i++){
        if(check[i])
        continue;
        
        check[i]=true;
        func(index+1,num+to_string(i));
        check[i]=false;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>arr[i];
    } 

   
    func(0,"");
    sort(answer.begin(),answer.end());
    // for(int i=0;i<answer.size();i++){
    //     cout<<answer[i]<<endl;
    // }

    cout<<answer[answer.size()-1]<<"\n";
    cout<<answer[0]<<"\n";

    //vector에 가능한 숫자조합 담겨있음
    //정렬을 통해 최댓값, 최솟값 찾기


}