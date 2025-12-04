#include <stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		list<char> res;
		auto t = res.begin();
		for (auto a : temp) {

			if (a == '<') {
				if (t != res.begin()) {
					t--;
				}
			}
			else if (a == '>') {
				if (t != res.end()) {
					t++;
				}
			}
			else if (a == '-') {
				if (t != res.begin()) {
					t--;
					t = res.erase(t);
				}
			}
			else {
				res.insert(t, a);
			}
		}
		for (auto a : res) {
			cout << a;
		}
		cout << "\n";

	}


	return 0;
}
