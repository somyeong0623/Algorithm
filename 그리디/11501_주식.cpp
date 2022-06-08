//11501. 주식 (답보고 이해 ........)
#include <iostream>
#include <vector>
using namespace std;

int TC;
long long answer;
int max_stock;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>TC;
    for(int t=1; t<=TC; t++){

        answer=0;
        max_stock=0;

        int n;
        cin>>n;
        vector<int> v(n);

        for(int i=0; i<n; i++){
            cin>>v[i];
         
        }

        for(int i=n-1; i>=0; i--){
            if(v[i]>max_stock)
                max_stock=v[i];
            else{
                answer+=(max_stock-v[i]);
            }
          
                  
        }
        cout<<answer<<"\n";

    }

}