// 6588. �������� ����

#include <iostream>
using namespace std;

const int MAX = 1000000;
int prime[MAX]; //�Ҽ� ��� �迭
int pn; //�Ҽ� ����
bool check[MAX];
// ���������� true, ������������ false

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i <= MAX; i++) {
		if (check[i] == false) {
			prime[pn++] = i;
			//prime[0]=2���� prime[1]=3, �̷������� ���
			for (int j = i + i; j <= MAX; j += i)
				check[j] = true;
		}
	}


	while (1) {
		int x;
		cin >> x;
		if (x == 0)
			break;
		for (int i = 1; i < pn; i++) {
			if (check[x - prime[i]] == false) {
				cout << x << " = " << prime[i] << " + " << x - prime[i] << "\n";
				break;
			}
		}


	}
}
