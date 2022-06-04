//9904:순열1
#include <iostream>
#include <string>
#include<string.h>
using namespace std;

int TC;
int n;
string answer;
int arr[100001];



int main() {
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
				answer = "Yes";
				memset(arr, 0, sizeof(arr));

		cin >> n;
		for (int i= 0; i < n; i++) {
			int x;
			cin >> x;
			arr[x]++;
		}

		/*for (int i = 1; i <= n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;*/

		for (int i = 1; i <= n; i++) {
			if (arr[i] != 1) {
				answer = "No";
				break;
			}
		}
		cout << "#" << t << " "<<answer<<"\n";
	}

}