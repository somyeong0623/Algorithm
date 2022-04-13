#include <iostream>
#include <cmath>

using namespace std;

int arr[10];
int t;
double sum;
double avg;

int main(){
    cin>>t;
    for(int i=1; i<=t; i++){
        sum=0;
        avg=0;
        for(int j=0; j<10; j++){
            cin>>arr[j];

            sum+=arr[j];
        }
        avg=sum/10;
        // cout<<"#"<<i<<" "<<sum<<"\n";
        // cout<<"#"<<i<<" "<<avg<<"\n";
        cout<<"#"<<i<<" "<<round(avg)<<"\n";

    }
}