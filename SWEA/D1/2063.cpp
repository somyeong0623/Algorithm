//중간값 찾기
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int main(){
    cin>>n;
    vector<int> v;

        int cnt=n/2+1;
        for(int j=0; j<n; j++){
            int x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        cout<<v[cnt-1]<<"\n";
       



}