//10032: 과자 분배
#include <iostream>
using namespace std;

int TC;
int n, k;
int answer;

int main() {
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> n >> k;

		if (n%k == 0)
			answer = 0;
		else
			answer = 1;

		cout << "#" << t << " " << answer << "\n";
	}
	

}