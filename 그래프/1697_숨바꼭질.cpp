//1697번: 숨바꼭질
#include <iostream>
#include <queue>
using namespace std;

int n,k;
bool visit[100001];
int dist[100001];
int next;

void bfs(){
    queue<int> q;
    visit[n]=true;
    q.push(n);

    while(!q.empty()){
    int cur=q.front();
    q.pop();


     for(int i=0; i<3; i++){
        
        if(i==0)
            next=cur-1;
        else if(i==1)
            next=cur+1;
        else
            next=2*cur;

        if(next>=0 && next<=100000){
            if(visit[next]==false){
                visit[next]=true;
                dist[next=dist[cur]+1;
                q.push(next);

                if(next==k)
                return;
            }
        }

     }
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>n>>k;

    bfs();
    cout<<dist[k]<<"\n";
}