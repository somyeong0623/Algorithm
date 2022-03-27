//15654번 : N과 M(5)
#include <iostream>
#include <algorithm>
using namespace std;

bool check[10001];
int arr[10];
int input[10];

void func(int index, int n, int m){
    if(index>m){
        for(int i=1; i<=m; i++){
            cout<<arr[i] <<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=0; i<n;i++){
     
        if(check[input[i]])
        continue;

        check[input[i]]=true;
        arr[index]=input[i];
        func(index+1,n,m);
        check[input[i]]=false;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        input[i]=x;
    }
    sort(input,input+n);
    // func(index,n,m);

    func(1,n,m);
}
