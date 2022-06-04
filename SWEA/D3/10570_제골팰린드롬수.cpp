//10570번: 제곱 팰린드롬 수
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int answer;

bool isRight(int n) {
	string s = to_string(n);
	int s_size = s.size();
	for (int i = 0; i < s.size()/2; i++) {
		if (s[i] != s[s_size - i - 1])
			return false;
	}

	return true;
}

int main() {
	int TC;
	cin >> TC;

	for (int t = 1; t <= TC; t++) {
		cout << "#" << t << " ";
		answer = 0;

		int a, b;
		cin >> a >> b;
		int start_num = sqrt(a);
		int end_num = sqrt(b);
		for (int i = start_num; i <= end_num; i++) {
			if (i*i < a)
				continue;

			if(isRight(i)){
				if (isRight(i*i)) {
					answer++;
					//cout << "i:" << i << endl;
				}
			}
		}

		cout << answer << "\n";
	}
}