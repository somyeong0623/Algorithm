//1. 마당 잔디 깎기
//영인코드
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int tc;
int n,m; //세로, 가로크기
int d; //잔디 깎는 일 수
int nxt; //잔디 깎는 다음날
int oil[20001]; //기름 배열
long long answer; //정답
long long temp;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    //테스트케이스 수
    cin>>tc;
    for(int t=1; t<=tc; t++){
        answer=0; //answer 초기화
        nxt=0; //nxt 초기화
        
        cin>>n>>m>>d; //세로, 가로, 일 수
        int v_size=n*m; //잔디 전체갯수
        vector<int> v; //이차원 배열 -> 1차원 벡터로 입력받기
        vector<int> day;
        // 잔디배열 입력
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x;
                cin>>x;
                v.push_back(x);
                day.push_back(0);
            }
        }
        
        // 기름배열 입력
        for(int i=0; i<d; i++){
            cin>>oil[i];
        }
        
        sort(v.begin(), v.end(), greater<int>()); //잔디벡터 내림차순 정렬
        
        //잔디 깎기
        for(int i=1; i<=d; i++){
            
            int cnt=oil[i-1]; //기름 갯수
            temp=0;
            
            //temp: i+1일차에 깎은 총 잔디량
            for(int j=0; j<cnt; j++){
                if(nxt>=v_size) {
                    nxt=0;
                }
                if(v[nxt]+i-day[nxt]==2) { temp+=1; }
                else { temp+=(v[nxt]+i-day[nxt]-1); }
                day[nxt]=i;
                v[nxt]=1;
                nxt++;
            }
            
            answer+=temp*i;
        }
        
        cout<<"#"<<t<<" "<<answer<<"\n";
        
    }
    
}
