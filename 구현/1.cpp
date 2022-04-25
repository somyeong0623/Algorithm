#include <iostream>
#include <queue>
#include <vector>

using namespace std;
priority_queue<int,vector<int>, greater<int>> pq;
vector<int> v;

int main(){
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(9);
    v.push_back(10);
    v.push_back(12);

    for(int i=0; i<v.size(); i++){
        pq.push(v[i]);
    }

    for(int i=0; i<pq.size(); i++){
        cout<<pq[i]<<"\n";
    }

    



}