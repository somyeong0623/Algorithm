//9317. 석찬이의 받아쓰기
#include <iostream>
#include <string>
using namespace std;

int TC;
int n;
int answer;

int main() {
	cin >> TC;
	string s1;
	string s2;

	for (int t = 1; t <= TC; t++) {
		answer = 0;
		cin >> n;

		cin >> s1;
		cin >> s2;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == s2[i])
				answer++;
		}

		cout << "#" << t << " " << answer << "\n";
	}
}