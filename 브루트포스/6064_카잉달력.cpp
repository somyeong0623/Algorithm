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
		// x,y둘다 만족시켜야 하므로 1부터 m*n까지다 확인하지 말고
		// x 만족하는 수 만 건너뛰면서 y 만족하는지 확인하자
		// 그럼 시간복잡도는 m*n 이 아니라 m이 된다.

		for (int i = x; i <= m * n; i+=m) {
			if (i % n == y){
				day = i;
				break;
			}
		}
		cout << day << "\n";
	}
}
