#include <iostream>
#include <cmath>
using namespace std;

int func(int n){
    int a=sqrt(n);
    for(int i=1; i<=a; i++){
        if(i*i==n)
            return 1;
    }
    return 0;
}

int main(){
    cout<<func(9)<<endl;
    cout<<func(693953651)<<endl;
    cout<<func(756580036)<<endl;

}