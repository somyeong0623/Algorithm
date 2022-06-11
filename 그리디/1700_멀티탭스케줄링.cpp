//1700. 멀티탭 스케줄링
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n,k;
bool check[101];
int answer;

int main(){
    cin>>n>>k;
    for(int i=0; i<k; i++){
        int x;
        cin>>x;
        if(check[x]==false){
            v.push_back(x);
            check[x]=true;
        }
    }

    answer=v.size()-2;
    cout<<answer<<"\n";
}