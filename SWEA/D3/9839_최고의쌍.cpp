//9839: 최고의 쌍
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int TC;
int n;
int arr[1000];
int answer;

bool isRight(int n) {
	string s = to_string(n);
	for (int i = 1; i < s[i]; i++) {
		if (s[i]!= s[i - 1]+1)
			return false;
	}

	return true;
}

int main() {
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> n;
		answer = -1;
		memset(arr, 0, sizeof(0));

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < n-1; i++) {
			for (int j = i + 1; j < n; j++) {
				int temp = arr[i] * arr[j];
				if (!isRight(temp))
					continue;
				if (temp > answer)
					answer = temp;
			}
		}

		cout << "#" << t << " " << answer << "\n";
	}

}