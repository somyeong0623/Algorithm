//11445: 무한 사전
#include <iostream>
#include <string>
using namespace std;

int TC;
char answer;

 int main() {
	 cin >> TC;
	 for (int t = 1; t <= TC; t++) {
		 string p, q;
		 cin >> p;
		 cin >> q;

		 if (p + 'a' == q)
			 answer = 'N';
		 else
			 answer = 'Y';

		
		 cout << "#" << t << " " << answer << "\n";



	 }
	
	

}