#include <string>
#include <iostream>
#include <vector>

using namespace std;
int parent[200];
bool check[200];

int find(int x){
    if(x==parent[x])
        return x;
    
    return parent[x]=find(parent[x]);
}

void unions(int x,int y){
    x=find(x);
    y=find(y);
    
    if(x<y)
        parent[y]=x;
    else
        parent[x]=y;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    //부모를 자기자신으로 초기화
    for(int i=0; i<n; i++){
        parent[i]=i;
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) //자기자신이면 continue;
                continue;
            
            if(computers[i][j]==1){
                if (parent[i]==parent[j]) //이미 부모 같으면 패스
                    continue;
                
                unions(i,j);
            }
        }
        
    }
    
//     for(int i=0; i<n; i++){
//         parent[i]=find(i);
//     }
    
    //다른 부모값이 몇개인지 세기
        for(int i=0; i<n;i++){
            cout<<parent[i]<<" ";
           if(check[parent[i]]==false){
               answer++;
               check[parent[i]]=true;
           }
        }
        
    
    return answer;
}