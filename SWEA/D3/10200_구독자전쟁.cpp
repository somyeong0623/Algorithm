//10200구독자 전쟁
#include <iostream>
using namespace std;
int TC;
int n, a, b;
int max_num, min_num;

int main() {
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> n >> a >> b;
		if (a >= b)
			max_num = b;
		else
			max_num = a;
		
		if (a + b <= n)
			min_num = 0;
		else
			min_num = a + b - n;
			

		cout << "#" << t << " " << max_num << " " << min_num << "\n";
	}
}