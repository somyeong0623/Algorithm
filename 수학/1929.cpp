//1929. ¼Ò¼ö ±¸ÇÏ±â

#include <iostream>
#include <cmath>
using namespace std;

bool func(int x) {
	if (x == 1)
		return 0;
	for (int i = 2; i <=sqrt(x); i++) {
		if (x % i == 0)
			return 0;
	}
	return 1;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y;
	cin >> x >> y;
	for (int i = x; i <= y; i++) {
		if (func(i))
			cout << i << "\n";
	}

}
