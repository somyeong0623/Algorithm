/*
5<=N<=15

2<=M<=N

각 영역의 파리 갯수 30 이하

*/

#include <iostream>
using namespace std;

int TC;
int n, m;
int answer;
int sum;
int arr[16][16];

void func(int n, int m)
{
    answer = 0;

    for (int i = 0; i < n - m+1; i++)
    {
        for (int j = 0; j < n - m+1; j++)
        {
            sum = 0;
            for (int k = i; k < i + m; k++)
            {
                for (int l = j; l < j + m; l++)
                {
                    sum += arr[k][l];
                }
            }

            if (answer < sum)
                answer = sum;
        }
    }
}

int main()
{
    cin >> TC;
    for (int t = 1; t <= TC; t++)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        func(n, m);
        cout << "#" << t << " " << answer << "\n";
    }
}