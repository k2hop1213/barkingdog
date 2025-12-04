#include <stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int>a;
	int n;
	cin >> n;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp) {
			a.push(temp);
			res += temp;
		}
		else {
			res -= a.top();
			a.pop();
		}
	}
	cout << res;

	return 0;
}
