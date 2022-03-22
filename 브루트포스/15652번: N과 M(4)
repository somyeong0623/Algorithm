//15652. N과 M(4)
#include <iostream>
using namespace std;

int check[10];
int arr[10];

void func(int index,int start, int n,int m){
    if(index>m){
        for(int i=1; i<=m; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=start; i<=n; i++){
        arr[index]=i;
        func(index+1,i,n,m);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    func(1,1,n,m);  
 
}
