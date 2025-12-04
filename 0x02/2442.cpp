#include <stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a = 1;
	int b = (2 * n - 1) / 2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < b; j++) {
			cout << " ";
		}
		for (int j = 0; j < a; j++) {
			cout << "*";
		}
		a += 2;
		b -= 1;

		cout << "\n";
	}


	return 0;
}
