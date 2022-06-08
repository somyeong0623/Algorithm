#include <iostream>
using namespace std;

int answer;

int func(int n){
    answer=0;
    for(int i=1; i<=n; i++){
        if(i%3==0 || i%5==0)
            answer+=i;
    }
    return answer;
}

int main(){
    cout<<func(16)<<endl;

    cout<<func(34567)<<endl;
    cout<<func(27639)<<endl;
}