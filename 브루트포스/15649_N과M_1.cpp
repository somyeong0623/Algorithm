//15649. N과 M(1)

#include <iostream>
using namespace std;

int arr[9];
int check[9]; // 숫자 사용했는지 여부 체크
int cnt = 1; // 수열 갯수


void func(int index, int n, int m) {


	if (index > m) {
		for (int j = 1; j <= m; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";
		return;
	}
		
	
	for (int i = 1; i <= n; i++) {
		if (check[i] == true)
			continue;
		check[i] = true;
		arr[index] = i;
		func(index + 1, n, m);
		
		//수열 출력 부분
	

		check[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	

	func(1, n, m);

}
