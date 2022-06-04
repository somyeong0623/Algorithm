//11387. 몬스터 사냥

#include <iostream>
#include <cmath>
using namespace std;

int TC;
long long d, l, n;
long long answer;

int main() {

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cout << "#" << t << " ";

		cin >> d >> l >> n;
		

		answer = d * n + d * l*n*(n - 1) / 200;
		cout << answer << "\n";
	}

}