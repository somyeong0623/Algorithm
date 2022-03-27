//15651. N과 M(3)
#include <iostream>
using namespace std;

bool check[10];
int arr[10];
void func(int index, int n, int m){
    if(index>m){
        for(int i=1; i<=m; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=1; i<=n; i++){
        arr[index]=i;
        func(index+1,n,m);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    func(1,n,m);
}
