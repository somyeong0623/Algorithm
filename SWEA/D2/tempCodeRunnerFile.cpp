/*
N명중 N/10명에게 동일한 평점 부여

A+ A0 A- B+ B0 B- C+ C0 C- D0

중간35% 기말45% 과제20%

N은 10의 배수 10<=N<=100
K:알고 싶은 학생 번호, K는 1이상 N이하

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    int n, k;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        cin >> n >> k;
        vector<double> v1;
        vector<double> v2;

        for (int j = 0; j < n; j++)
        {
            int a, b, c;
            double sum;

            cin >> a >> b >> c;
            sum = a * 0.35 + b * 0.45 + c * 0.2;
            v1.push_back(sum);
            v2.push_back(sum);
        }

        sort(v1.begin(), v1.end(),greater<int>());

        cout<<"#"<<i<<" ";
        double score=v2[k-1]; //k번 학생의 총점
        // cout<<"score: "<<score<<"\n";
        
        
        // cout<<"-----v1 -------"<<"\n";
        // for(int a=0; a<n; a++){
        //     cout<<v1[a]<<" ";
        // }

        // cout<<"-------v2-----"<<"\n";
        // for(int b=0; b<n; b++){
        //     cout<<v2[b]<<" ";
        // }
        // cout<<endl;

        int index;
        for(int j=0; j<n; j++){
            if (v1[j] == score)
            {
                index = j;
                // cout<<"index: "<<index<<"\n";
                break;
            }
        }
      index=index/(n/10);
      if(index==0){
          cout<<"A+"<<"\n";
      }else if(index==1){
          cout<<"A0"<<"\n";
      }else if(index==2){
          cout<<"A-"<<"\n";
      }else if(index==3){
          cout<<"B+"<<"\n";
      }else if(index==4){
          cout<<"B0"<<"\n";
      }else if(index==5){
          cout<<"B-"<<"\n";
      }else if(index==6){
          cout<<"C+"<<"\n";
      }else if(index==7){
          cout<<"C0"<<"\n";
      }else if(index==8){
          cout<<"C-"<<"\n";
      }else{
          cout<<"D0"<<"\n";
      }
    }
}
