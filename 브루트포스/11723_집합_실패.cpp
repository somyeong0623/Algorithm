//11723번: 집합
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    string str;
    int x;
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>str;
        if(str=="add"){
            cin>>x;
            auto it=find(v.begin(),v.end(),x);
            if(it==v.end()) // 없는 경우만 push
            v.push_back(x);
        }
        else if(str=="remove"){
            cin>>x;
            auto it=find(v.begin(),v.end(),x);
            if(it!=v.end()) //있는 경우
            v.erase(v.begin()+(*it)-1);
        }
        else if(str=="check"){
            cin>>x;
             auto it=find(v.begin(),v.end(),x);
            if(it!=v.end())
            cout<<1<<"\n";
            else
            cout<<0<<"\n";
        }
        else if(str=="toggle"){
            cin>>x;
            auto it=find(v.begin(),v.end(),x);
            if(it!=v.end())
             v.erase(v.begin()+(*it)-1);
            else
            v.push_back(x);
        }
        else if(str=="all"){
            vector <int>().swap(v); 
            for(int i=1; i<=20; i++){
                v.push_back(i);
            }
        }else{
             vector <int>().swap(v); 
        }

        // for(int i=0; i<v.size(); i++){
        //     cout<<v[i]<<" ";
        // }
        cout<<endl;
    }
}
// 이 코드 왜 런타임에러인지 모르겠다 