//10580. 전봇대
#include <iostream>
#include <vector>
using namespace std;



int main() {
	int TC;
	int answer;
	cin >> TC;
	for (int t = 1; t <= TC; t++) {

		vector<pair<int, int>> v;
		answer = 0;

		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back({ a,b });
		}
		for (int i = 0; i < v.size(); i++) {
			int cur_left = v[i].first;
			int cur_right = v[i].second;

			for (int j = 0; j < i; j++) {
				int prev_left = v[j].first;
				int prev_right = v[j].second;

				if (cur_left > prev_left && cur_right > prev_right)
					continue;
				if (cur_left < prev_left && cur_right < prev_right)
					continue;

				answer++;
			}
		}


		cout << "#" << t << " " << answer << "\n";

	}

}