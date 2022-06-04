//9229: 한빈이와 Spot Mart
#include <iostream>
using namespace std;

int TC;
int n, m;
int answer;

int main() {
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		int arr[1000];
		answer = -1;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];

		}
		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j++) {
				if (arr[i] + arr[j] <= m) {
					if (answer < arr[i] + arr[j])
						answer = arr[i] + arr[j];
				}
			}
		}

		cout << "#" << t << " " << answer << "\n";

	}

}