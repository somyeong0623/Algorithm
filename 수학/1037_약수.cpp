//1037. 약수
// 1 2 3 4 6 12
// 1 5 25
// 1 5 25 125 625
#include<iostream>
using namespace std;

int arr[55];
long long result;


int main() {
	int cnt;
	cin >> cnt;
	int max = 0;
	int min = 1000000;
	for (int i = 1; i <= cnt; i++) {
		cin >> arr[i];
		if (max < arr[i]) {
			max = arr[i];
		}
		if (min > arr[i]) {
			min = arr[i];
		}
	}

	if (cnt == 1) {
		result = arr[cnt]*arr[cnt];
	}
	else {
		result = max * min;
	}
	cout << result;

}
