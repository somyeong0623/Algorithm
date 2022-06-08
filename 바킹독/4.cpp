#include <iostream>
#include <cmath>
using namespace std;

int func(int n){
    int answer=0;
    for(int i=0; pow(2,i)<=n; i++){
        int temp=pow(2,i);
        if(temp<=n)
            answer=temp;
    }
    return answer;
}

int main(){
    cout<<func(5)<<endl;
    cout<<func(97615282)<<endl;
    cout<<func(1024)<<endl;

}