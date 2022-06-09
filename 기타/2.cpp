#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define MAX 1000001
using namespace std;

priority_queue <long long, vector<long long>, greater<long long>> pq;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		pq.push(num);
	}

	for (int i = 0; i < m; i++) {
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();

		long long c = a + b;
		pq.push(c);
		pq.push(c);

	}

	long long sum = 0;
	while(!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum;
}