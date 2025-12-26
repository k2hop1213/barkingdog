#include <stdc++.h>
using namespace std;
long long arr[1000001];
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)cin >> arr[i];
	sort(arr, arr + m);
	
	long long left = 1;
	long long right = arr[m - 1];
	long long res = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		int cnt = 0;

		for (int i = 0; i < m; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt >= n) {
			if (mid > res) {
				res = mid;
			}
			left = mid + 1;

		}
		else {
			right = mid - 1;
		}
	}

	cout << res;

	return 0;
}
