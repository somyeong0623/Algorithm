//11736: 평범한 숫자
#include <iostream>
#include <vector>;
using namespace std;


int TC;
vector<int> v;
int cnt;
int min_num;  int max_num;

int main() {

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		v.clear();
		cnt = 0;
		cout << "#" << t << " ";
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			v.push_back(x);
		}
		for (int i = 1; i < v.size() - 1; i++) {
			//v[i-1], v[i], v[i+1] 중에 최솟값 결정
			min_num = v[i - 1];
			if (v[i] < min_num)
				min_num = v[i];
			if (v[i + 1] < min_num)
				min_num = v[i + 1];

			//v[i-1], v[i], v[i+1] 중에 최댓값 결정
			max_num = v[i - 1];
			if (v[i] > max_num)
				max_num = v[i];
			if (v[i + 1] > max_num)
				max_num = v[i + 1];


			//v[i]가 평범한 수인지 확인
			if (v[i] != min_num && v[i] != max_num)
				cnt++;
		}

			cout << cnt << "\n";

		


	}
 

}