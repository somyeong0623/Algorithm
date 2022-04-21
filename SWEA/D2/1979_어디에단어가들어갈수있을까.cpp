/*

5<=N<=15
2<=K<=N
흰색 1, 검은색 0

*/

#include <iostream>
using namespace std;

int TC, n, k;
int arr[15][15];
int cnt;
bool flag;

void func()
{
    //가로형 살펴보기
   for(int i=0; i<n; i++){
       for(int j=0; j<=n-k; j++){
           flag=true;

           if(arr[i][j]==1){
               //제일 왼쪽칸이거나 바로 왼쪽칸이 막혀있어야 함.
               if(j==0 || arr[i][j-1]==0){
                   for(int x=1; x<k; x++){
                       if(arr[i][j+x]==0){
                           flag=false;
                           break;
                       }
                   }

                   //k개가 비어있는지 확인나서는, 그 k개 다음칸이 마지막칸이거나 0이어야함.
                   if(flag==true){
                       if(j+k==n || arr[i][j+k]==0){
                        //    cout<<"가로 "<<"i: "<<i<<", j: "<<j<<"\n";
                           cnt++;
                       }
                   }
               }
           }
       }
   }


   //세로형 살펴보기
   for(int i=0; i<=n-k; i++){
       for(int j=0; j<n; j++){
           flag=true;

           if(arr[i][j]==1){
               //제일 위쪽칸이거나 바로 위쪽칸이 막혀있어야함
               if(i==0 || arr[i-1][j]==0){
                   for(int x=1; x<k; x++){
                       if(arr[i+x][j]==0){
                           flag=false;
                           break;
                       }
                   }

                   //k개가 비어있는지 확인나서는, 그 k개 다음칸이 마지막칸이거나 0이어야함.
                   if(flag==true){
                       if(i+k==n || arr[i+k][j]==0){
                        //    cout<<"세로 "<<"i: "<<i<<", j: "<<j<<"\n";
                           cnt++;
                       }
                   }
               }
           }
       }
   }
}

    int main()
    {
        cin >> TC;
        for (int i = 1; i <= TC; i++)
        {
            cin >> n >> k;
            cnt = 0;

            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    cin >> arr[j][k];
                }
            }
            func();
            cout << "#" << i << " " << cnt << "\n";
        }
    }