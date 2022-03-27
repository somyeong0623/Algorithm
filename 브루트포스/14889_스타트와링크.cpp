//14889번:스타트와 링크
//개어렵다 .... 이건 절대 못풀듯....포기할래 ..
#include<iostream>
#include<vector>
using namespace std;

int arr[21][21];
int answer=1000;
vector<int> first;
vector<int> second;
int n;
//i번 사람이 first팀일때, second팀일 때를 쭈욱 비교
int func(int index,vector<int> &first,vector<int> &second){
    if(index==n){ 
        // if(first.size()!=n/2)
        // return -1;
        // if(second.size()!=n/2)
        // return -1;
        
        //반반씩 나뉘었으면
        int t1=0;
        int t2=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j)
                continue;
                
                t1+=arr[first[i]][first[j]];
                t2+=arr[second[i]][second[j]];
            }
        }

        int diff=t1-t2;
        if(diff<0)
        diff=-diff;
        return diff;

    }
   
    
    int ans=-1; //답의 초깃값
    //index번 사람이 first팀에 들어간 경우
    first.push_back(index);
    int t1=func(index+1,first,second);
    if(ans==-1 ||(t1!=-1 && ans>t1)){
        ans=t1;
    }
    first.pop_back();
    // index사람이 first 팀에서의 할수있는건 다 했으니까 빼줘야함
    second.push_back(index);
    int t2=func(index+1,first,second);
    if(ans==-1||(t2!=-1 && ans>t2)){
        ans=t2;
    }
    second.pop_back();
    return ans;
    }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int sum=0;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    cout<<func(0,first,second)<<"\n";
    


}