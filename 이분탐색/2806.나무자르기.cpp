//2805. 나무 자르기
/*
나무의 수 1<=N<=1,000,000
가져가려는 나무의 길이 1<=M<=2,000,000,000
각 나무의 높이 0<=h<= 1,000,000,000 (나무 높이가 0인게 말이 되나 ..? ㅇㅂㅇ)
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
long long tree[1000001];

long long sum(int h){
    long long total=0;
    for(int i=0; i<n; i++){
        if(tree[i]>=h){
            total+=(tree[i]-h);
        }
    }
    return total;
}

long long bt(){
    long long st=0;
    long long en=tree[n-1];
    long long mid=0;
    while(st<=en){
        mid=(st+en)/2;
        if(sum(mid)>=m){
            st=mid+1;
        }else{
            en=mid-1;
        }
    }

    return en; //return할때 st,mid,en 중에 헷갈린다 ......
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>tree[i];
    }
    sort(tree,tree+n);
    long long h=bt();
    cout<<h<<"\n";

}