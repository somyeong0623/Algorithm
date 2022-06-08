//8931:제로
#include <iostream>
#include <stack>
using namespace std;



int TC;
int n;
int answer;

int main() {
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		stack<int> s;
		answer = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x == 0)
				s.pop();
			else
				s.push(x);
		}

		while (!s.empty()) {
			answer += s.top();
			s.pop();
		}

		cout << "#" << t << " " << answer << "\n";
	}

}
s