//14500. 테트로미노
#include <iostream>
using namespace std;

int arr[501][501];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//세로 n, 가로 m;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = 0;
	int sum = 0;

	// 1)1-1. ---- 모양
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m - 3; j++) {
			sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}
	//2)1-2 ---- 돌린모양 
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n - 3; j++) {
			sum = arr[j][i] + arr[j + 1][i] + arr[j + 2][i] + arr[j + 3][i];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//3) 2 정사각형 모양
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			sum = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//4) 3-1. 
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//5) 3-2
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			sum = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2] + arr[i][j + 2];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//6) 3-3
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//7) 3-4
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			sum = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i][j + 2];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//8) 3-5

	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			sum = arr[i + 2][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//9) 3-6
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			sum = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//10) 3-7
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j] + arr[i + 2][j];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//11) 3-8
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 2];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//12) 4-1
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			sum = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//13) 4-2
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			sum = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i][j + 2];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//14) 4-3
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			sum = arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1] + arr[i][j + 1];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//15) 4-4
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			sum = arr[i][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 1][j + 2];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//16) 5-1
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			sum = arr[i + 1][j] + arr[i + 1][j + 1] + arr[i][j + 1] + arr[i + 1][j + 2];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//17) 5-2
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			sum = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 1][j + 1];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//18) 5-3
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 2; j++) {
			sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}

	//19) 5-4
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 1; j++) {
			sum = arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
			//cout << "sum : " << sum << "\n";
			if (sum > ans)
				ans = sum;
			sum = 0;
		}
	}
	cout  << ans;
}

