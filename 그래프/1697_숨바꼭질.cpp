//1697번: 숨바꼭질
#include <iostream>
#include <queue>
using namespace std;

int n,k;
bool visit[200001];
int dist[200001];
int ncur;

void bfs(){
    queue<int> q;
    visit[n]=true;
    q.push(n);

    while(!q.empty()){
    int cur=q.front();
    q.pop();


     for(int i=0; i<3; i++){
        
        if(i==0) //-1 이동
            ncur=cur-1;
        else if(i==1) //+1 이동
            ncur=cur+1;
        else //*2 이동
            ncur=2*cur;

        /*처음엔 ncur범위를 10만으로 하였었다.
         생각해보면 k=10만이라고 가정했을때 *2연산으로 인해 10만을 넘어간 상태에서 -1연산을 몇번 하는것이 최선의 방법일 수도 있다.
         그런데 20만을 넘어가면 10만이 되려면 -1를 10만번 해야되므로 0에서시작해서 +1을 10만번 하는거랑 다른게 없게 된다.
         그러므로 20만으로 최대값을 잡으면 된다.
        10만이던, 20만이던 1억에비하면 매우 작으므로 시간은 괜찮다.

        첨에 10만으로 했는데 맞았는데 왜 맞았지 ?? 틀릴수도 있지 않나 ...?

         */

        if(ncur>=0 && ncur<=200000){
            if(visit[ncur]==false){
                visit[ncur]=true;
                dist[ncur]=dist[cur]+1;
                q.push(ncur);

                if(ncur==k)
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