///1874. 스택 수열
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<char> answer; //정답 보관 벡터
stack<int> st; 
queue<int> q;
bool flag; //불가능 여부 저장


int main(){
    flag= true;
    cin>>n;
    for(int i=0; i<n; i++){ //주어진 수열 queue에 담기
        int x;
        cin>>x;
        q.push(x);
       
    }

    int index=1; //1부터 N까지 차례대로 stack에 push하므로 push 하는 숫자저장.
    int cur=0; //stack의 top 값 
    while(!q.empty()){
        if(cur<q.front()){
            st.push(index);
            index ++;
            cur=st.top();
            answer.push_back('+');
        }
        else if(cur>=q.front()){
            if(st.top()!=q.front()){ //더이상 push 할 수 없을때, st.top이 q.front와 다르면 불가능한 경우이다.
                flag=false; //불가능한경우 flag 갱신하고 while문 끝내기.
                break;
            }
            st.pop();
            answer.push_back('-');
            q.pop();
            if(!st.empty()) //이 if문 없었더니 segmentation 오류났음.
                cur=st.top();
            
        }

    }
    if(flag==false) 
        cout<<"NO"<<"\n";
    else
        for(int i=0; i<answer.size(); i++){ //정답벡터 차례대로 출력
            cout<<answer[i]<<"\n";
        }
}