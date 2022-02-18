// 6588. 골드바흐의 추축

#include <iostream>
using namespace std;

const int MAX = 1000000;
int prime[MAX]; //소수 담는 배열
int pn; //소수 갯수
bool check[MAX];
// 지워졌으면 true, 안지워졌으면 false

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i <= MAX; i++) {
		if (check[i] == false) {
			prime[pn++] = i;
			//prime[0]=2부터 prime[1]=3, 이런식으로 담김
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
