#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> vec;
vector<int> v1;
vector<int> v2;

int main(){
   v1.push_back(0);
   v1.push_back(1);
   v1.push_back(1);
   vec.push_back(v1);


    v2.push_back(0);
    v2.push_back(2);
    v2.push_back(2);
    vec.push_back(v2);

    cout<<"hello"<<endl;
    cout<<"size: "<<vec.size()<<"\n";
}