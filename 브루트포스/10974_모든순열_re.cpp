//10974번: 모든 순열_re
#include <iostream>
using namespace std;
int n;
int arr[9];


bool func(int arr[],int n){
    int i=n-1;
    while(i>0 && arr[i-1]>arr[i])
    i--;


    if(i<=0)
    return false;

    int j= n-1;
    while(arr[i-1]>arr[j])
    j--;

    swap(arr[i-1],arr[j]);
    j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
 
    return true;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        arr[i]=i+1;
    }
    do{
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }while(func(arr,n));


}