#include <stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[10] = { 0 };

	int n;
	cin >> n;

	while (n > 0) {
		arr[n % 10]++;
		n /= 10;
	}

	int min = 0;

	for (int i = 0; i < 10; i++) {
		if (min < arr[i]) {
			if (i == 6 || i == 9)
				min = (arr[6] + arr[9] + 1) / 2;
			else min = arr[i];
		}
	}
	cout << min;

	return 0;
}
