//11688번 Calkin-Wilf tree 1
#include <iostream>
#include <string>
using namespace std;

int TC;
int a, b;
string s;


int main() {

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		cout << "#" << t << " ";
		a = 1; b = 1;
		
		cin >> s;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'L') {
				b = a + b;
			}
			else {
				a = a + b;
			}
		}
		cout << a << " " << b << "\n";

	}

}