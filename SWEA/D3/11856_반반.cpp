//11856. 반반
#include <iostream>
#include <string>
#include <map>
using namespace std;

int TC;
string s;
string answer;

int main() {

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		map <char, int> m;
		cout << "#" << t << " ";
		answer = "Yes";
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			m[s[i]]++;
		}

		for (auto i : m) {
			if ( i.second != 2) {
				answer = "No";
				break;
			}
		}

		cout << answer << "\n";
	}
}