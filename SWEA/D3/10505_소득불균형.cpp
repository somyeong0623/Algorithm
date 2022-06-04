//10505: 소득불균형
#include <iostream>
using namespace std;

int TC;
int n;
int sum;
double avg;
int cnt;

int main() {

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cin >> n;
		int arr[10000];
		sum = 0;
		cnt = 0;

		//입력받기
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i]; //전체합 계산
		}
		avg = sum / n; //평균 계산
		for (int i = 0; i < n; i++) {
			if (arr[i] <= avg) //각 소득이 평균이하인지 확인
				cnt++;
		}

		cout << "#" << t << " " << cnt << "\n";

	}

}