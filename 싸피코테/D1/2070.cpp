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
       int x,y;
       cin>>x>>y;

        cout<<"#"<<i<<" ";

       if(x>y)
       cout<<">"<<"\n";
       else if(x<y)
       cout<<"<"<<"\n";
       else
       cout<<"="<<"\n";
       


    }
}