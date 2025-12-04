#include <stdc++.h>
using namespace std;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int arr[20] = { 0 };
	for (int i = 1; i <= 20; i++)arr[i - 1] = i;

	for (int i = 0; i < 10; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = a - 1; j < (a + b) / 2; j++) {
			int temp = arr[j];
			arr[j] = arr[b - j + a - 2];
			arr[b - j + a - 2] = temp;

		}
	}
	for (int i = 0; i < 20; i++)cout << arr[i] << " ";
	return 0;
}
