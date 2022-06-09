//1744. 수 묶기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int answer;
int cnt_minus;
int cnt_plus;
int plus_index;
bool zero;// 0 존재하면 true, 존재안하면 false

int main(){
    cin>>n;
    vector<int> v(n);

    for(int i=0; i<n; i++){ //양수,음수 갯수 카운트
        cin>>v[i]; 
        if(v[i]>0)
            cnt_plus++;
        if(v[i]<0)
            cnt_minus++;
        if(v[i]==0)
            zero=true;
    }

    sort(v.begin(),v.end()); //오른차순 정렬

    for(int i=0; i<n; i++){
        if(v[i]>0){ //plus_index: 양수의 시작 인덱스
            plus_index=i;
            break;
        }
    }

    if(cnt_plus==0){ //양수가 없으면
        if(zero==true){//0이 있으면 
            plus_index=n-1;
        }else{ //0이 없으면
            plus_index=n;
        }
    }

    for(int i=plus_index; i<n; i++){ //양수 살펴보기
        if(cnt_plus%2==1){//양수가 홀수개면, 처음양수그냥 더하고 나머지는 두개씩 곱해서 answer에 더하기
            if(i==plus_index)
                answer+=v[i];
            else{
                if(i+1<n){
                    if(v[i]*v[i+1]>v[i]+v[i+1]) // 예제5 같은 경우있을수있으니, 곱해서 더한것과 각각 더한것중 더 큰것 확인
                        answer+=v[i]*v[i+1];
                    else
                        answer+=(v[i]+v[i+1]);
                    i++; //두 수 확인했으니까 i++ 해주어야함.
                }
            }
        }else{// 양수가 짝수개면 두개씩 곱해서 answer에 더하기
            if(i+1<n){
                  if(v[i]*v[i+1]>v[i]+v[i+1])
                        answer+=v[i]*v[i+1];
                    else
                        answer+=(v[i]+v[i+1]);
                i++;
            }
    
        }
    }

    for(int i=0; i<plus_index; i++){ //음수 살펴보기 
    // 음수가 홀수개던 짝수개던 두개씩 곱해서 answer에 더하면 되고, 홀수일경우 마지막 하나는 따로 answre에 더하면 됨
        if(i+1<plus_index){
            answer+=v[i]*v[i+1]; // 음수경우는 무조건 곱해서 더하는게 최댓값 만드는 방법임.
            i++;
        }else{
            answer+=v[i]; //홀수일경우 마지막 남은 음수 따로 더해주는 식
        }
       
    }

    cout<<answer<<"\n";
}
