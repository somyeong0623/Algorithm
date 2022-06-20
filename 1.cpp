#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


int tc;
int n,m; //세로, 가로크기
int d; //잔디 깎는 일 수
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
        
        cin>>n>>m>>d; //세로, 가로, 일 수
        int v_size=n*m; //잔디 전체갯수
        vector<int> v(v_size,0); //이차원 배열 -> 1차원 벡터로 입력받기
        // 잔디배열 입력
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x;
                cin>>x;
                v.push_back(x);
            }
        }
        
        // 기름배열 입력
        for(int i=0; i<d; i++){
            cin>>oil[i];
        }
    
        sort(v.begin(), v.end(), greater<int>()); //잔디벡터 내림차순 정렬

        cout<<"정렬 보자"<<endl;
        for(int i=0; i<v_size; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;

        //잔디 깎기
        for(int i=0; i<d; i++){

            //잔디 1씩 증가
            for(int k=0; k<v_size; k++){
                v[k]++;
            }

            //내림차순 정렬
            sort(v.begin(), v.end(), greater<int>());
            int cnt=oil[i]; //기름 갯수
            temp=0;

           // temp: i+1일차에 깎은 총 잔디량
            for(int j=0; j<cnt; j++){
                temp+=(v[j]-1); 
                v[j]=1;
            }

            answer+=(temp*(i+1));

        }

        cout<<"#"<<t<<" "<<answer<<"\n";
    
    }

}
