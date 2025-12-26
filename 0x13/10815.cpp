#include <stdc++.h>
using namespace std;

int arr[500001];
int arr1[500001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> arr[i];
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)cin >> arr1[i];
	sort(arr, arr + n);

	for (int i = 0; i < m; i++) {
		cout << binary_search(arr, arr + n, arr1[i]) << ' ';
	}


	return 0;
}
