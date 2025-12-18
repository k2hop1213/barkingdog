#include <bits/stdc++.h>
using namespace std;

int arr[1001][3];
int arr1[1001][3];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}
	arr1[0][0] = arr[0][0];
	arr1[0][1] = arr[0][1];
	arr1[0][2] = arr[0][2];
	for (int i = 1; i < n; i++) {
		arr1[i][0] = min(arr1[i - 1][1], arr1[i - 1][2]) + arr[i][0];
		arr1[i][1] = min(arr1[i - 1][0], arr1[i - 1][2]) + arr[i][1];
		arr1[i][2] = min(arr1[i - 1][0], arr1[i - 1][1]) + arr[i][2];
	}
	cout << min({ arr1[n - 1][0], arr1[n - 1][1], arr1[n - 1][2] });
	return 0;
}
