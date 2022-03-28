//10819번: 차이를 최대로
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;
int n;
int answer;

int func(vector<int> v, int n){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int sum=0;
    for(int i=1; i<n; i++){
        int diff=v[i]-v[i-1];
        if(diff<0)
        diff=-diff;

        sum+=diff;
    }
    return sum;
}

int main(){
    int result=0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
//     for(int i=0; i<n; i++){
//         cout<<v[i]<<" ";
//     }
//     cout<<"\n";

    int cnt=0;
    do{
        // cout<<"cnt : "<<cnt <<"\n";
        // cnt++;
        result = func(v,n);
        if(result>answer)
        answer=result;
    }
    while(next_permutation(v.begin(),v.end()));

    cout<<answer<<"\n";
}