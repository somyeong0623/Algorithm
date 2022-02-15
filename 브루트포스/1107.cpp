//1107. 리모컨
#include <iostream>
using namespace std;

bool broken[10];

int possible(int x) { //고장난키보드 있어서 입력할수 없으면0, 입력할 수 있으면 그 숫자의 길이 리턴
	if (x == 0) {
		if (broken[0])
			return 0;
		else
			return 1; // 0은 한자리니까
	}
	int len = 0;
	while (x > 0) {
		if (broken[x % 10]) {
			return 0;
		}
		else {
			len += 1;
			x /= 10;
		}
	}
	return len;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n;
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		broken[x] = 1; 
	}

	int ans = 100 - n;
	if (ans < 0)
		ans = -ans;

	int len = 0;
	int press = 0;

	for (int i = 0; i < 1000000; i++) {
		int c = i;
		len = possible(c);
		if (len > 0) {
			press = n - c;
			if (press < 0)
				press = -press;
			if (ans > len + press)
				ans = len + press;

		}
	}
	
	//cout << "최종 len : " << len << "\n";
	//cout << " 최종pres : " << press << "\n";
	cout << ans;
}
