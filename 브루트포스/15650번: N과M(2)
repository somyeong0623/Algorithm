//15650. N과M(2)
#include <iostream>
using namespace std;

bool check[10];
int arr[10];

void func(int index, int start, int n, int m){
    if(index>m){
        for(int i=1; i<=m; i++){
            cout<<arr[i]<<" ";
        }

        cout<<"\n";
        return;
    }

    for(int i=start; i<=n; i++){
        if(check[i])
        continue;

        check[i]=true;
        arr[index]=i;
        func(index+1,i+1,n,m);
        check[i]=false;

    }
}

int main(){
    int n,m;
    cin>>n>>m;
    func(1,1,n,m);


}
//start : index번째에 올 수 있는 수는 start~N 
