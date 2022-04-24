/*
2<=N<=10,000,000
N=2a x 3b x 5c x 7d x 11e
*/
#include <iostream>
#include <vector>
using namespace std;

int TC;
int n;
int cnt = 0;
int main()
{

    cin >> TC;
    for (int t = 1; t <= TC; t++)
    {
        cin >> n;
        vector<int> v;

        // 2
        cnt = 0;
        while (n % 2 == 0)
        {
            n = n / 2;
            cnt++;
        }
        v.push_back(cnt);

        // 3
        cnt = 0;
        while (n % 3 == 0)
        {
            n = n / 3;
            cnt++;
        }
        v.push_back(cnt);

        // 5
        cnt = 0;
        while (n % 5 == 0)
        {
            n = n / 5;
            cnt++;
        }
        v.push_back(cnt);

        // 7
        cnt = 0;
        while (n % 7 == 0)
        {
            n = n / 7;
            cnt++;
        }
        v.push_back(cnt);

        // 11
        cnt = 0;
        while (n % 11 == 0)
        {
            n = n / 11;
            cnt++;
        }
        v.push_back(cnt);
        
        //출력
        cout<<"#"<<t<<" ";
        for(int i=0; i<v.size(); i++ ){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
}