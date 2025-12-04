#include <stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[26] = { 0 };

	string s;
	cin >> s;

	for (auto c : s) {
		arr[c - 'a']++;
	}
	for (auto c : arr) {
		cout << c << " ";
	}

	return 0;
}
