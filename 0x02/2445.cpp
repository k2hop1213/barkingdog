#include <stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int a = 1;
	int b = n - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a; j++) {
			cout << "*";
		}
		for (int j = 0; j < 2 * b; j++) {
			cout << " ";
		}
		for (int j = 0; j < a; j++) {
			cout << "*";
		}
		a += 1;
		b -= 1;
		cout << "\n";
	}
	a = n - 1;
	b = 1;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < a; j++) {
			cout << "*";
		}
		for (int j = 0; j < 2 * b; j++) {
			cout << " ";
		}
		for (int j = 0; j < a; j++) {
			cout << "*";
		}
		a -= 1;
		b += 1;
		cout << "\n";
	}


	return 0;
}
