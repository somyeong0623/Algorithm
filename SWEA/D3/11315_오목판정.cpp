//11315번: 오목판정
#include <iostream>
#include <string>
using namespace std;

int TC;
char arr[20][20];
int cnt;
string answer;
int n;


bool func(int x, int y) {
	cnt = 1;
	int nx = x;
	int ny = y;

	//가로
	while (true) {
		ny += 1;
		if (ny >= n)
			break;

		if (arr[nx][ny] == '.')
			break;

		if (arr[nx][ny] == 'o') {
			cnt++;
			//cout << "cnt: " << cnt << endl;
		}
		if (cnt == 5) {
			return true;
		}

	}

	//세로
	nx = x;
	ny = y;
	cnt = 1;
	
	while (true) {
		nx += 1;
		if (nx >= n)
			break;

		if (arr[nx][ny] == '.')
			break;

		if (arr[nx][ny] == 'o') {
			cnt++;
			//cout << "cnt: " << cnt << endl;
		}
		if (cnt == 5) {
			return true;
		}

	}

	//오른쪽 아래 대각선
	nx = x;
	ny = y;
	cnt = 1;

	while (true) {
		nx += 1;
		ny += 1;

		if (ny >= n || nx>=n)
			break;

		if (arr[nx][ny] == '.')
			break;

		if (arr[nx][ny] == 'o') {
			cnt++;
			//cout << "cnt: " << cnt << endl;

		}
		if (cnt == 5) {
			return true;
		}
	
	}

	//왼쪽 아래 대각선
	nx = x;
	ny = y;
	cnt = 1;

	while (true) {

		nx += 1;
		ny -= 1;
		if (ny< 0 || nx>= n)
			break;

		if (arr[nx][ny] == '.')
			break;

		if (arr[nx][ny] == 'o') {
			cnt++;
			//cout << "cnt: " << cnt << endl;
		}
		if (cnt == 5) {
			return true;
		}

	}

	return false;
}

int main() {
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cout << "#" << t << " ";
		answer = "NO";
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 'o') {
					if (func(i, j)){
						answer = "YES";
						break;
					}
				}
			}
		}

		cout << answer << "\n";
		

	}

}