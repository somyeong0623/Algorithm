//6064 카잉 달력
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	int m, n, x, y;
	cin >> t;
	int day = 0; 
	while (t--) {
		day = -1;
		cin >> m >> n >> x >> y;
		if (x == m)
			x = 0;
		if (y == n)
			y = 0;
		for (int i = 1; i <= m * n; i++) {
			if ((i % m == x) && (i % n == y)) {
				day = i;
				break;
			}
		}
		cout << day << "\n";
	}
}
