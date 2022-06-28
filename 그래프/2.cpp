#include <iostream>
#include <queue>

using namespace std;

queue<pair<int,pair<int,int>>> q;

int main(){
    q.push({1,{2,3}});
    int a=q.front().first;
    int b=q.front().second.first;
    int c=q.front().second.second;

    cout<<a<<" "<<b<<" "<<c<<"\n";    
}