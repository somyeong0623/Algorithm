//6064. 카잉 달력
//몰라서 구글링함...
/*
1<=M,N<=40,000
1<=x<=M, 1<=y<=N
*/
#include <iostream>
using namespace std;

int m,n,x,y;
int answer;
int TC;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>TC;
        for(int t=1; t<=TC; t++){
        cin>>m>>n>>x>>y;

        answer=-1;
        int last=m*n; 
        //마지막 해는 m,n의 최소공배수인데 최소공배수는 m*n보다 작거나 같으므로 m*n으로 그냥 설정함.

        
        for(int i=x; i<=last; i+=m){ //x부터 m씩더하면서 확인
            if((i-1)%n+1==y){ //ex. answer=60,m=12,n=10인경우 x=0이아니라 10이 되어야하니까 고려한것.
                answer=i;
                break;
            }
        }
        cout<<answer<<"\n";
    }
}