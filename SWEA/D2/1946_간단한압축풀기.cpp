/*
[제약사항]

1. 압축된 문서의 알파벳과 숫자 쌍의 개수 N은1이상 10이하의 정수이다. (1 ≤ N ≤ 10)

2. 주어지는 알파벳 Ci는 A~Z의 대문자이다. (i는 줄의 번호로 1~N까지의 수)

3. 알파벳의 연속된 개수로 주어지는 수 Ki는 1이상 20이하의 정수이다. (1 ≤ Ki ≤ 20, i는 줄의 번호로 1~N까지의 수)

4. 원본 문서의 너비는 10으로 고정이다.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int TC;
int n;
int cnt;



int main()
{
    cin >> TC;
    for (int t = 1; t <= TC; t++)
    {
        cnt = 0;
        vector<char> v;
        // cout<<"v.size: "<<v.size()<<"\n";
        v.push_back(0);
        cin >> n;
        
        //입력받아서 벡터에 푸쉬
        for (int i = 0; i < n; i++)
        {
            char a;
            int b;
            cin >> a >> b;

            for (int j = 0; j < b; j++)
            {
                v.push_back(a);
            }
        }

        //출력
        cout << '#' << t << "\n";
        for (int i = 1; i <= v.size(); i++)
        {
            
            cout << v[i];
            if (i % 10 == 0)
            {
                cout << "\n";
            }
        }
        cout<<"\n";

    }
}