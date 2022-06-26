//2. 엑스칼리버를 찾아서 (은노코드)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int dy[4] = {1, 0, -1, 0};
const int dx[4] = {0, 1, 0, -1};

bool ok(int y, int x, vector<vector<char>>& mat){
    return (y >=0 && y < mat.size() && x >=0 && x < mat[0].size() ? true : false);
}
int getMinDistance(int y, int x, int goalY, int goalX, vector<vector<char>>& mat){
    vector<vector<bool>> visit(mat.size(), vector<bool>(mat[0].size(), false));
    queue<pair<pair<int, int>, int>> pending;
    pending.push({{y, x}, 0});
    while(!pending.empty()){
        pair<pair<int, int>, int> now = pending.front(); pending.pop();
        int now_y = now.first.first;
        int now_x = now.first.second;
        int distance = now.second;
        if(now_y == goalY && now_x == goalX)
            return distance;
        
                
        for(int j=0; j < 4; j++){
            int next_y = now_y + dy[j];
            int next_x = now_x + dx[j];
            if(ok(next_y, next_x, mat) && mat[next_y][next_x] != 'X' && visit[next_y][next_x] == false){
                visit[next_y][next_x]=true;
                pending.push({{next_y, next_x}, distance + 1});
            }
        }
    }
    return -987654321;
}
int main() {
    
    int T;
    cin >> T;
    for(int test_case = 1; test_case <= T; test_case++){
        string s = "ABC";
        int N, M, R, K;
        int minDist = 987654321;
        cin >> N >> M >> R >> K;
        R--, K--;
        vector<vector<char>> mat(N, vector<char>(M, 0));
        
        int initR = R;
        int initK = K;
        vector<pair<int, int>> vec_pos(3, {0, 0});
        pair<int ,int> S_pos;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> mat[i][j];
                if(mat[i][j] == 'A' || mat[i][j] == 'B' || mat[i][j] == 'C')
                    vec_pos[mat[i][j] - 'A'] = {i, j};
                else if(mat[i][j] == 'S')
                    S_pos = {i, j};
            }
        }
        do{
            int distance=0;
            R = initR;
            K = initK;
            for(int i=0; i<s.size(); i++){
                int next_y = vec_pos[s[i]-'A'].first;
                int next_x = vec_pos[s[i]-'A'].second;
                distance += getMinDistance(R, K, next_y, next_x, mat);
                //cout << s[i] << ' ' << distance << endl;
                R = next_y;
                K = next_x;
            }
            distance += abs(R-S_pos.first) + abs(K-S_pos.second);
            minDist = min(minDist, distance);
        }while(next_permutation(s.begin(), s.end()));
        cout << "#" << test_case << ' ' << minDist << endl;
    }
    
}
