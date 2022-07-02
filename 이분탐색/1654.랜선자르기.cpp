//1654. 랜선 자르기
/*
가지고 있는 랜선갯수  1<=K<=10,000
필요한 랜선갯수 1<=N<=1,000,000
K<=N
랜선의 길이 <=2^31-1 (자연수)

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k,n;
vector<int> v;
int cnt;
int answer;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>k>>n;
    for(int i=0; i<k; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());
    
    long long st=1;
    long long en=v[k-1];//v[0]인줄 알았는데, 최대 길이 구하는거니까 en=max값으로 설정해야함!
    long long mid=0;
    while(st<=en){
        mid=(st+en)/2;
        cnt=0;
        for(int i=0; i<k; i++){
            cnt+=(v[i]/mid);
        }
        if(cnt>=n){
            if(mid>answer){ //가능한 랜선 최대길이 구해야 하므로 
                answer=mid;
            }
            st=mid+1;
        }else{
            en=mid-1;
        }
    }

    cout<<answer<<"\n";
}
/*
반례
2 2
1
2147483647
-> 이런경우 있을수 있어서 long long으로 해야함.
*/