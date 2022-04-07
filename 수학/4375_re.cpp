//4375
#include <iostream>
#include <string>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin>>n) {
		int num = 0;
		for (int i = 1;; i++) {
			num = num * 10 + 1;
			num = num % n;
			if (num == 0) {
				cout << i << "\n";
				break;
			}
		}
	}
}
