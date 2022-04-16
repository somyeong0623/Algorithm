// 간단한 369게임
/*
1~N 규칙에 맞게 출력
10<=N<=1,000
*/
#include <iostream>
#include <string>
using namespace std;
string s;

bool flag;
int n;
int main()
{   
    cin>>n;
    for(int i=1; i<=n; i++){
        string x=to_string(i);
        flag =false;
        for(int j=0; j<x.size(); j++){
            if(x[j]=='3' || x[j] =='6' || x[j]=='9'){
                cout<<"-";
                flag=true;
            }
        }
        if(flag==true){
            cout<<" ";
        }

        if(flag==false){
            cout<<i<<" ";
        }

    }


}