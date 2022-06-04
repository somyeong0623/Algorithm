//10059. 유효기간
#include <iostream>
#include <string>
using namespace std;

int TC;
string answer;

int main() {
	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		answer = "";
		string s;
		cin >> s;
		string first = s.substr(0, 2);
		string second = "";
		second += s.substr(2, 4);


		int first_num = 0;
		first_num = stoi(first);
		int second_num = 0;
		second_num = stoi(second);

		if (first_num == 0 && second_num == 0)
			answer = "NA";
		else if (first_num == 0 && second_num > 0) {
			if (second_num > 12)
				answer = "NA";
			else
				answer = "YYMM";
		}
		else if (second_num == 0 && first_num > 0) {
			if (first_num > 12)
				answer = "NA";
			else
				answer = "MMYY";
		}
		else if (first_num > 12 && second_num > 12)
			answer = "NA";
		else if (first_num > 12 && second_num <= 12)
			answer = "YYMM";
		else if (first_num <= 12 && second_num > 12)
			answer = "MMYY";
		else
			answer = "AMBIGUOUS";


		cout << "#" << t << " " << answer << "\n";

	}
}