//10804. 문자열의 거울상
#include <iostream>
#include <string>
using namespace std;


int main() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cout << "#" << t << " ";
		string answer;
		string s;
		cin >> s;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == 'b')
				answer += 'd';
			else if (s[i] == 'd')
				answer += 'b';
			else if (s[i] == 'p')
				answer += 'q';
			else
				answer += 'p';
		}

		cout << answer << "\n";
		

	}

}