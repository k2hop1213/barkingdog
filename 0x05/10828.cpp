#include <stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	stack<int> a;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int temp;
			cin >> temp;
			a.push(temp);
		}
		else if (s == "pop") {
			if (a.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << a.top() << "\n";
				a.pop();
			}
		}
		else if (s == "size") {
			cout << a.size() << "\n";

		}
		else if (s == "empty") {
			cout << a.empty() << "\n";
		}
		else {
			if (a.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << a.top() << "\n";
			}
		}
	}



	return 0;
}
