//1978. �Ҽ�ã��
#include <iostream>
using namespace std;

int cnt = 0;

//�Ҽ��̸� 1, �Ҽ��ƴϸ�0 ����
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