//1978. 소수찾기
#include <iostream>
using namespace std;

int cnt = 0;

//소수이면 1, 소수아니면0 리턴
bool func(int x) {
	if (x == 1)
		return 0;
	for (int i = 2; i < x; i++) {
		if (x % i == 0)
			return 0;
	} 
	return 1;

}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (func(x))
			cnt++;

	}
	cout << cnt;
}
