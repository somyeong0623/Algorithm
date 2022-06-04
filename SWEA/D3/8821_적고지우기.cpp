//8821번: 적고 지우기
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int TC;
int cnt[10];
int answer;


int main() {
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		memset(cnt, 0, sizeof(cnt));
		answer = 0;
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			int cur = s[i] - '0';
			cnt[cur]++;

		}
	/*	for (int i = 0; i <= 9; i++) {
			cout << cnt[i] << endl;
		}*/

		for (int i = 0; i <= 9; i++) {
			if (cnt[i] % 2 == 1)
				answer++;
		}

		cout << "#" << t << " " << answer << "\n";
	}
}