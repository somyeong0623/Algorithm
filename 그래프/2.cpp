#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int,int>> q;

int arr[10][10];
int n;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
           cin>>arr[i][j];
        }
    }

    cout<<"\n";

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}
