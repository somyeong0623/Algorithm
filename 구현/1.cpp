#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
priority_queue<int,vector<int>, greater<int>> pq;
vector<int> v;

int main(){

    int n=3;
    int k=2;

    vector<int> v;
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }


    vector<int> tempVector;

    for(int i=0; i<k; i++){
        tempVector.push_back(1);

    }

    for(int i=0; i<v.size()-k; i++){
        tempVector.push_back(0);
    }
   
   sort(tempVector.begin(), tempVector.end());

   do{
       for(int i=0; i<tempVector.size(); i++){
           if(tempVector[i]==1){
               cout<<v[i]<<" ";
           }
       }
       cout<<endl;
   }while(next_permutation(tempVector.begin(), tempVector.end()));





}