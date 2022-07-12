#include <iostream>
using namespace std;

int arr[]={5,6,7,8,9,10};
int main(){
  int k=10;
  if(++k>10 && k++==11){
    k=k+10;
  }
  cout<<k<<"\n";

  int n = 17/4 + 3.5;
  cout<<"n:"<<n<<"\n";
}