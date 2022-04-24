#include <iostream>
#include <cmath>

using namespace std;
bool check[10];

int main(){

    int num=123;
    string s = to_string(num);
    
    cout<<s<<"\n";
    for(int i=0; i<s.size(); i++){
        int x=s[i]-'0';
        check[x]=true;

    }


    for(int i=0; i<10; i++){
        cout<<check[i]<<"\n";
    }
    
}