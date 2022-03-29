// 2776번: 암기왕
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, n, m;

bool func(vector<int> v, int target, int n)
{
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;
    while (start <= end)
    {
        if (v[mid] == target)
        {
            return true;
        }
        else if (v[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end= mid - 1;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while (t--)
    {
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int y;
            cin >> y;
            cout << func(v, y, n) << "\n";
        }
    }

    cout<<"hello"<<"\n";
}