//15961. 회전 초밥
/*
전 초밥 벨트에 놓인 접시의 수 N , 2 ≤ N ≤ 3,000,000
초밥의 가짓수 d,  2 ≤ d ≤ 3,000
연속해서 먹는 접시의 수 k, 2 ≤ k ≤ 3,000 (k ≤ N)
쿠폰 번호 c, 1 ≤ c ≤ d
*/

#include <iostream>

using namespace std;

int n,d,k,c;
int menu[3000001]; //회전 초밥 입력받기
int cnt[3001]; //각 초밥의 갯수
int answer;// 정답
int kind_cnt; //종류 갯수


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>d>>k>>c;// 접시 수, 초밥의 가짓수, 연속해서 먹는 접시의 수, 쿠폰 번호
    for(int i=0; i<n; i++){
        cin>>menu[i];
    }

    cnt[c]++;
    kind_cnt++;

    //첫 k개 살펴보기
    for(int i=0; i<k; i++){ 
        if(cnt[menu[i]]==0){
            kind_cnt++;
        }
        cnt[menu[i]]++; // 갯수 갱신
    }
    answer=kind_cnt;// 초밥 종류의 갯수
 

    for(int i=k; i<n+k-1; i++){

        // 고려하는 K개 초밥의 범위를 앞으로 한칸 미는 과정

        // 밀려난 초밥 살펴보기
        cnt[menu[i-k]]--; 
        if(cnt[menu[i-k]]==0){
            kind_cnt--;
        }
        
        //새로 들어온 초밥 살펴보기
        if(cnt[menu[i%n]]==0){  //회전이므로 mod연산
            kind_cnt++;
        }
        cnt[menu[i%n]]++;

        //kind_cnt의 최댓값 저장
        if(answer<kind_cnt)
            answer=kind_cnt;
    }

    cout<<answer<<"\n";


}