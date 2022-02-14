//1476. 날짜 계산
#include <iostream>
using namespace std;

//E : 1~15
//S : 1~28
//M : 1~19

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int e, s, m;
	cin >> e >> s >> m;

	int year = 1;
	while (1) {
		if (e == 15)
			e = 0;
		if (s == 28)
			s = 0;
		if (m == 19)
			m = 0;
		if ((year%15==e)&&(year%28==s)&&(year%19==m))
			break;
		year++;
	}
	cout << year;
}
