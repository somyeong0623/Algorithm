//9997번: 미니멀리즘 시계
#include <iostream>
using namespace std;

int TC;
int h, m;
int n;

int main() {
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
	
		cin >> n;
		h = n / 30;
		m = n % 30 * 2;

		cout << "#" << t << " " << h << " " << m << "\n";
	}

}