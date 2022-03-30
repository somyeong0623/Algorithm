//10972번 : 다음순열
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int arr[3];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // int n;
    // cin>>n;
    // for(int i=0; i<n; i++){
    //     int x;
    //     cin>>x; 
    //     v.push_back(x);
    // }

    // if(next_permutation(v.begin(),v.end())){
    // for(int i=0; i<n; i++){
    //     cout<<v[i]<<" ";
    //  }
    // }
    // else{for(int i=0; i<n; i++){
    //     cout<<v[i]<<" ";
    //  }
    //     cout<<-1<<"\n";
    //}
    cout<<'.'-'A';
    arr['.'-'A']=1;
    for(int i=0; i<3; i++){
        cout<<arr[i] <<" ";
    }

}