#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool a[2000][2000];
vector<int> g[2000];
vector<pair<int,int>> edges;


vector<int> v(3);
int main(){
    fill(v.begin(), v.end(), -4);

    for(int i=0; i<v.size(); i++){
        cout<<v[i] <<" ";
    }
    

}