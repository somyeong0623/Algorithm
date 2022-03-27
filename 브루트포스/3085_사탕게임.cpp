//3085. 사탕 게임
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int check(vector<string>& a) {
	int cnt = 1;
	int n = a.size();
	int max = 0;
	//가로줄(행 검사)
	for (int i = 0; i < n; i++) {
		cnt = 1;
		for (int j = 0; j < n-1; j++) {
			if (a[i][j] == a[i][j + 1]) {
				cnt += 1;
		
			}
			else {
				cnt = 1;
			}
			if (cnt > max)
				max = cnt;
		}
	}
	cnt = 1;
	//세로줄(열 검사)
	for (int j = 0; j < n ; j++) {
		cnt = 1;
		for (int i = 0; i < n - 1; i++) {
			if (a[i][j] == a[i+1][j]) {
				cnt += 1;
				
			}
			else {
				cnt = 1;
			}
			if (cnt > max)
				max = cnt;
		}
	}
	return max;
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int answer = 0;

	//오른쪽이랑 swap
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			swap(a[i][j-1], a[i][j]);
			if (check(a) > answer)
				answer = check(a);
			swap(a[i][j-1], a[i][j ]);
		}
	}
	//아래랑 swap
	for (int j= 0; j < n; j++) {
		for (int i = 1; i < n; i++) {
			swap(a[i-1][j], a[i][j]);
			if (check(a) > answer)
				answer = check(a);
			swap(a[i-1][j], a[i][j]);
		}
	}

	cout << answer;
	
	
}
