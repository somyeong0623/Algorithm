//10912번: 외로운 문자
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


string answer; 
string s;

int main() {
	int TC;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		map <char, int> m;
		cout << "#" << t << " ";
		answer = "";

		
		cin >> s;
		sort(s.begin(), s.end());

		for (int i = 0; i < s.size(); i++) {
			m[s[i]]++;
		}

		for (auto i:m) {
			if (i.second%2==0)
				continue;
			else
				answer += i.first;
		}

		if (answer.size() == 0)
			cout << "Good" << "\n";
		else
			cout << answer << "\n";
	}

}