/*
N, M
3<= N,M<=20

*/
#include <iostream>
using namespace std;

int TC;
int n, m;
int a[20];
int b[20];
int answer, sum;

int main()
{
    cin >> TC;
    for (int t = 1; t <= TC; t++)
    {
        cin >> n >> m;

        answer = -987654321;
        sum = 0;

        // a배열 입력
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // b배열 입력
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        //더하기
        //1.n<=m일때
        if (n <= m)
        {
            for (int i = 0; i <= m - n; i++)
            {
                sum = 0;
                for (int j = 0; j < n; j++)
                {
                    // cout << "a:" << j << ",b:" << i + j << "\n";
                    sum += a[j] * b[i + j];
                }

                if (sum > answer)
                {
                    answer = sum;
                }
            }
        
        }else{// 2. n>m일때
            for (int i = 0; i <= n - m; i++)
            {
                sum = 0;
                for (int j = 0; j < m; j++)
                {
                    // cout << "a:" << i+j << ",b:" <<  j << "\n";
                    sum += a[i+j] * b[j];
                }

                if (sum > answer)
                {
                    answer = sum;
                }
            }
        }

        cout << "#" << t << " " << answer << "\n";
    }
}