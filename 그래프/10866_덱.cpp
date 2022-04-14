//10866_덱
#include <iostream>
#include <deque>
using namespace std;

int n;
string s;
int x;
deque<int> dq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int size=0;
    cin>>n;
    while(n--){
        cin>>s;
      if(s=="push_front"){
          cin>>x;
        dq.push_front(x);
      }else if(s=="push_back"){
          cin>>x;
          dq.push_back(x);
      }else if(s=="pop_front"){
          if(dq.size()==0)
          cout<<-1<<"\n";
          else{
          cout<<dq.front()<<"\n";
          dq.pop_front();
          }

      }else if(s=="pop_back"){
          if(dq.size()==0)
          cout<<-1<<"\n";
          else{
              cout<<dq.back()<<"\n";
              dq.pop_back();
          }

      }else if(s=="size"){
          cout<<dq.size()<<"\n";

      }else if(s=="empty"){
          if(dq.empty())
          cout<<1<<"\n";
          else
          cout<<0<<"\n";

      }else if(s=="front"){
          if(dq.size()==0)
          cout<<-1<<"\n";
          else
          cout<<dq.front()<<"\n";
    
      }else{ //back인 경우
        if(dq.size()==0)
        cout<<-1<<"\n";
        else
        cout<<dq.back()<<"\n";

      }
    }
      



}