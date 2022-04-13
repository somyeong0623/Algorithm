#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<string>> v;
queue<pair<int,int>> q;

int main(){
    q.push(make_pair(1,2));
    q.push(make_pair(2,3));
    q.push(make_pair(2,3));
    q.push(make_pair(4,3));
    q.push(make_pair(5,5));
    q.push(make_pair(5,5));
    q.push(make_pair(5,5));

    cout<<q.size()<<"\n";

    for(int i=0; i<q.size(); i++){
        cout<<q.front().first << " "<<q.front().second<<"\n";
        q.pop();
    }
    



}
