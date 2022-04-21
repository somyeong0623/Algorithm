// 모르겠어서 구글링하고 이해

#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays){
    vector<int> answer;

    map<string, int> music; //각 장르별로 play횟수 저장
    map<string,map<int,int>> musiclist; //각 장르별로 어떤 노래가 몇번씩 play됐는지 저장

    for(int i=0; i<genres.size(); i++){
        music[genres[i]]+=plays[i]; //music map에 장르별 플레이횟수 추가
        musiclist[genres[i]][i]=plays[i]; //musiclist map에 노래번호와 플레이 횟수 추가

    }

    //music의 장르가 다 없어질때까지 반복
    while(music.size()>0){
        string genre="";
        int max=0;

        //제일 플레이횟수 많은 장르찾기
        for(auto mu : music){
            if(max<mu.second){
                max=mu.second;
                genre=mu.first;
            }
        }

        //위에서 찾아낸 장르마다 2곡 넣어야하므로 2번 반복
        for(int i=0; i<2; i++){
            int val=0; //플레이 횟수
            int ind=-1; //노래의 인덱스

            for( auto ml : musiclist[genre]){
                if(val<ml.second){
                    val=ml.second;
                    ind=ml.first;
                }
            }

            //장르에 노래가 1곡뿐이면 반복문 탈출
            if(ind==-1)
                break;

            answer.push_back(ind);
            musiclist[genre].erase(ind); //answer에 추가한 노래는 이제 삭제해야함.
        }
          //장르 하나에서 2개찾기 완료했으면 그 장르는 삭제.
           music.erase(genre);
    }   
    return answer;
}