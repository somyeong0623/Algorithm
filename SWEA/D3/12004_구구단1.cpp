//12004. 구구단 1
#include <iostream>
#include <string>
using namespace std;

int TC;
string answer;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		answer = "No";
		cout << "#" << t << " ";

		int n;
		cin >> n;

		for (int i = 1; i <= 9; i++) {
			if (n%i == 0) {
				int a = n / i;
				if (a >= 1 && a <= 9) {
					answer = "Yes";
					break;
				}
			}
		}

		cout<< answer << "\n";
	}

	

}