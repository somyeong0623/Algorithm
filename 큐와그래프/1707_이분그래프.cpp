// 1707: 이분그래프
/*
테케 K
정점 V
간선 E

2<=K<=5
1<=v<=20,000
1<=E<=200,000

*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int k, v, e;
vector<int> vec[20001];
queue<int> q;
int color[20001];//집합-> 색깔(1,2)를 나타냄
bool flag; //대답 출력시에 사용

bool bfs(int x){
    queue<int> q;
    q.push(x);
    color[x] = 1; //처음정점(1번정점)은 1번색깔이라고 가정  

    while (!q.empty()){
        int y = q.front();
        q.pop();

        for (int i = 0; i < vec[y].size(); i++) {
            int z = vec[y][i];

             if (color[z] == 0){
                color[z] = (color[y] == 1) ? 2 : 1;
                q.push(z);

            }
            else if (color[y] == color[z]){
              return false;
            }
        }
    }

    return true;
}

int main()
{
    cin >> k;
    for (int i = 0; i < k; i++){
        int v, e;
        cin >> v >> e;

        for (int j = 0; j < e; j++){
            int u, v;
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        flag=true;
        for(int i=1; i<=v; i++){
            if(color[i]==0){
                if(bfs(i)==false){
                    flag=false;
                    break;
                }
            }
        }
        
        if(flag==true)
        cout<<"YES"<<"\n";
        else
        cout<<"NO"<<"\n";

        memset(color, 0, sizeof(color)); // color 배열 초기화
        for (int i = 1; i <= v; i++) { //vector 배열 clear
            vec[i].clear();

        }
    }
}