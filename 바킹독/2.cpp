#include <iostream>
using namespace std;

int func(int arr[],int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]+arr[j]==100)
            return 1;
        }

    }
    return 0;
}


int main(){
    int arr1[3] ={1,52,48};
    cout<<func(arr1,3)<<endl;
    int arr2[2] ={50,42};
    cout<<func(arr2,2)<<endl;
    int arr3[4] ={4,13,63,87};
    cout<<func(arr3,4)<<endl;

}