#include <stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	list<char> a;

	for (auto i : s) {
		a.push_back(i);
	}
	auto t = a.end();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char temp;
		cin >> temp;
		if (temp == 'L') {
			if (t != a.begin()) {
				t--;
			}
		}
		else if (temp == 'D') {
			if (t != a.end()) {
				t++;
			}
		}
		else if (temp == 'B') {
			if (t != a.begin()) {
				t--;
				t = a.erase(t);
			}
		}
		else {
			char temp1;
			cin >> temp1;
			a.insert(t, temp1);
		}
	}
	for (auto i : a) {
		cout << i;
	}


	return 0;
}
