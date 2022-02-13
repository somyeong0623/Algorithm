//2309. 일곱 난쟁이
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int arr[10];
	int sum = 0;
	int x = 0;
	int y = 0;
	for (int i = 1; i <= 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 10);

	for (int i = 1; i <= 9; i++) {
		for (int j = i + 1; j <= 9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				x = i;
				y = j;
			}
		}
	}

	for (int i = 1; i <= 9; i++) {
		if (i == x)
			continue;
		if (i == y)
			continue;

		cout << arr[i] << "\n";
	}


}
