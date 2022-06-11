//2231. 분해합
#include <iostream>
#include <string>
using namespace std;

int n;
int answer;
int temp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    string s;
    cin>>s;
    int num=stoi(s);

    for(int i=1; i<num; i++){
        string cur=to_string(i);
        temp=i;

        for(int j=0; j<cur.size(); j++){
            temp+=(cur[j]-'0');
        }
        if(temp==num){
            answer=i;
            break;
        }
    }
    cout<<answer<<"\n";

}