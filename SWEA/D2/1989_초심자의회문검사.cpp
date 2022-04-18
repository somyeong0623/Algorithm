/*
각 단어길이 3이상 10이하
*/
#include <iostream>
using namespace std;

bool flag;

int main(){
    int T;
    cin>> T;
    for(int i=1; i<=T; i++){
        string s;
        cin>>s;
        flag=true;

        for(int i=0; i<s.size()/2; i++){
            if(s[i]!=s[s.size()-1-i]){
                flag=false;
                break;
            }
        }
        
        cout<<"#"<<i<<" ";
        if(flag==true){
            cout<<1<<"\n";
        }else{
            cout<<0<<"\n";
        }

    }

}