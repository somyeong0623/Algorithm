/*
1~N까지 홀수는 더하고 짝수는 뱀.
1<=N<=10

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int T;
    double sum;
    double answer;

    cin>>T;
    for(int i=1; i<=T; i++){
      vector<double> v;
      sum=0; 
      for(int j=0; j<10; j++){
          double x;
          cin>>x;
          v.push_back(x);
      }

      sort(v.begin(), v.end());
      for(int j=1; j<9; j++){
          sum+=v[j];
      }
        answer=round(sum/8);

        cout<<"#"<<i<<" "<<answer<<"\n";
    }
}