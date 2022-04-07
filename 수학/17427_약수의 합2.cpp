//17427. 약수의 합
//몰라서 답 봄...

#include <iostream>
#include <cmath>
using namespace std;
//1 5 25
//12= 1 2 3 4 6 12 = 28

long long func(int n) {
	long long result = 0;
	for (int i=1; i<=n; i++){
		int cnt = n / i; //cnt는 i를 약수로갖는 갯수, 즉 [N/i](내림)개
		result += (i * cnt);
	}
	return result;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << func(n);
}
