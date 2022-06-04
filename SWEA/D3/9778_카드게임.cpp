//9778번: 카드게임
#include <iostream>
#include <string>
using namespace std;

int TC;
int n;
int sum;
int cnt1, cnt2;
string answer;

int main() {
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		sum = 0;
		cnt1 = 0;
		cnt2 = 0;

		int arr[12] = {0, 0,4,4,4,4,4,4,4,4,16,4 };
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			arr[x]--;
			sum += x;
			
		}
		//cout << "sum: " << sum << endl;
			int temp = 21 - sum;
			for (int j = 2; j <= 11; j++) {
				if (j <= temp)
					cnt1 += arr[j];
				else
					cnt2 += arr[j];
			}

			if (cnt1 >= cnt2)
				answer = "GAZUA";
			else
				answer = "STOP";
		

		cout << "#" << t << " " << answer << "\n";
		
	}

}