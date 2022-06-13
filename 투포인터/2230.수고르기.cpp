//2230. 수 고르기
/*
1 ≤ N ≤ 100,000
0 ≤ M ≤ 2,000,000,000
0 ≤ |A[i]| ≤ 1,000,000,000

첫째 줄에 두 정수 N, M이 주어진다. 다음 N개의 줄에는 차례로 A[1], A[2], …, A[N]이 주어진다.
첫째 줄에 M 이상이면서 가장 작은 차이를 출력한다. 항상 차이가 M이상인 두 수를 고를 수 있다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n,m;
int st,en;
int temp;
int answer=2000000000;

vector<int> v;

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin>>n>>m;
//     for(int i=0; i<n; i++){
//         int x;
//         cin>>x;
//         v.push_back(x);
//     }
//     sort(v.begin(), v.end());

//     //i도 O(n)만큼 움직이고, j도 O(n)만큼 움직이므로 O(n)시간안에 해결가능하다.
//     for(int i=0; i<n; i++){
        
//         for(int j=i+1; j<n; j++){
            
//             temp=v[j]-v[i];
//             if(temp>=m){
//                 if(temp<answer)
//                     answer=temp;
//                 break;
//             }
//         }
//     }


//     cout<<answer<<"\n";
    
// }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);

    }
    sort(v.begin(), v.end());
    int en=0;
    for(int st=0; st<n; st++){
        while(en<n && v[en]-v[st]<m)
            en++;

        if(en==n) //en이 범위를 벗어나면 종료
            break;

        if(answer>v[en]-v[st])
            answer=v[en]-v[st];
    }

    cout<<answer<<"\n";
}